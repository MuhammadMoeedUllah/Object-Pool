
#pragma once
#include <mutex>
#include <bits/stdc++.h>
#include <vector>
#include <stack>
#define RAW_ARRAY_SIZE 50
#define MAX_QUEUE_SIZE 50
namespace objectPool{

    class raw_data{
    public:
        raw_data(){
            _byteArray= new char[RAW_ARRAY_SIZE];
        }

        explicit raw_data(const char *arr, int size){
            if(size <=0 || size >= RAW_ARRAY_SIZE-2){//leaving 1 char for null character
                return;
            }
            if(_byteArray)
                delete [] _byteArray;
            _byteArray= new char[ RAW_ARRAY_SIZE];

            _size = size;
            std::strncpy(_byteArray,arr,_size);
            _byteArray[_size]='\0';
        }

        raw_data(const raw_data& other){
            if (_byteArray == other._byteArray)
                return;
            if(_byteArray ==nullptr)
                _byteArray= new char[RAW_ARRAY_SIZE];
            std::strncpy(_byteArray,other._byteArray, RAW_ARRAY_SIZE);

        }

        bool copy(const char * arr, int size){
            if (_byteArray == arr)
                return false;
            //leaving last char for null character
            if(size <=0 || size >= RAW_ARRAY_SIZE-2){
                return false;
            }
            _size =size;
            std::memcpy( _byteArray, arr ,_size);
            _byteArray[_size]='\0';
            return true;
        }

        [[nodiscard]] const char * get_data()const{
            return _byteArray;
        }

        void reset(){
            _size = 0;
            if(_byteArray)
                _byteArray[0] = '\0';
        }

        ~raw_data(){
            if(!_byteArray)
                return;
            delete [] _byteArray;
        }

    private:
        char *_byteArray=nullptr;
        int _size=0;
    };
    class ObjectPool;
    class DataBucket: public std::enable_shared_from_this<DataBucket>{
    public:
        explicit DataBucket(ObjectPool *mypool, const uint&myKey);
        DataBucket& operator=(const DataBucket&) =default;
        DataBucket(const DataBucket&) =default;

        bool reset(){
            for (auto&each:data) {
                each.reset();
            }
            return true;
        }
        bool pop( std::string &ret ){

            if ( bucket_is_empty()){
                return false;
            }
            ret = data[index--].get_data();
            return true;
        }
        const char *  pop( ){

            if (bucket_is_empty()){
                return nullptr;
            }
            return data[index--].get_data();
        }
        const char * front(){
            return data[index].get_data();
        }
        const char *  at( const uint &pos){

            if (bucket_is_empty() || pos >= MAX_QUEUE_SIZE || pos>index){
                return nullptr;
            }
            return data[pos].get_data();
        }


        bool push(const char * str, size_t size){
            if(bucket_is_full())
                return false;
            // index starts at -1
            if(!data[++index].copy(str,size)){
                return false;}
            return true;
        }

        std::shared_ptr<DataBucket> getSharedptr() {
            return shared_from_this();
        }
        std::weak_ptr<DataBucket> getWeakptr() {
            return weak_from_this();
        }
        bool bucket_is_full()const{
            return (index >= (MAX_QUEUE_SIZE-1));
        }
        bool bucket_is_empty()const{
            return (index < 0);
        }

        int getSize()const{
            return index;
        }
        bool releaseBucket()const;
        ~DataBucket(){}
    private:
        void clear(){
            for (auto&each:data){
                each.reset();
            }
            index=-1;
        }
    private:
        uint _myKey;
        int index=-1;
        std::vector<raw_data>  data;
        // TODO make this work with weak pointer
        ObjectPool* _myPool = nullptr;
        friend class ObjectPool;
    };//class bucket

    //TODO Create a result type object for Queue Pool class using std::optional
    class ObjectPool: public std::enable_shared_from_this<ObjectPool>{
        enum bucket_status{
            EMPTY=0,
            IN_USE=1,
        };
    public:
        ObjectPool()=delete;
        explicit ObjectPool(uint size=50){
            poolSize = size;
            objects.reserve(size);
            bucketStatus.reserve(size);
            for (int i=0;i<poolSize;i++) {
                objects.emplace_back(std::make_shared<DataBucket>(this, i));
                bucketStatus[i] =bucket_status::EMPTY;
            }
        }
        std::shared_ptr<ObjectPool> getSharedptr() {
            return shared_from_this();
        }
        std::weak_ptr<ObjectPool> getWeakptr() {
            return weak_from_this();
        }
        std::shared_ptr<DataBucket> getBucket()noexcept{
            try{
                std::lock_guard<std::mutex> lck(myMutex);
                int index =findEmptyBucket();
                if(index == -1) {
                    return nullptr ;
                }
                bucketStatus[index] = bucket_status::IN_USE;
                objects[index]->reset();
                return (objects[index]);
            }
            catch(std::exception &e){
                return nullptr;
            }
        }

        void print(){
            for (auto&e:bucketStatus)
                std::cout<<e.first << " "<<e.second<<"\n";
        }
    private:
        bool returnBucket(int key)noexcept{
            try{
                std::lock_guard<std::mutex> lck(myMutex);
                if(key <0 || key>= poolSize || bucketStatus[key] !=bucket_status::IN_USE ){
                    return false;
                }
                bucketStatus[key] =bucket_status::EMPTY;
                objects[key]->clear();
                return true;
            }
            catch(std::exception &e){
                return false;
            }
        }

        int16_t findEmptyBucket(){
            for (auto & each:bucketStatus){
                if (each.second == bucket_status::EMPTY){
                    return each.first;
                }
            }
            return -1;
        }
    private:
        int poolSize;
        std::mutex myMutex;
        std::vector <std::shared_ptr<DataBucket>> objects;
        std::unordered_map <int,bucket_status> bucketStatus;
        friend class DataBucket;
    };

    // defined here because of forward declaration & circular dependency
    bool DataBucket::releaseBucket() const {
        try{
            if(_myPool)
                return _myPool->returnBucket(_myKey);
            return false;
        }
        catch(std::exception &e){
            std::cout<<"Exception : "<<e.what()<<"\n";
            return false;
        }
    }
    DataBucket::DataBucket( ObjectPool * mypool, const uint&myKey) {
        //filling bucket with empty data
        data.reserve(MAX_QUEUE_SIZE);
        for(int i=0;i<MAX_QUEUE_SIZE;i++)
            data.emplace_back();
        _myKey = myKey;
        _myPool = mypool;
    }

}//namespace object pool
