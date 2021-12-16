#include "pool/objectPool.hpp"

using namespace objectPool;

int main(){

    ObjectPool pool(3) ;

    auto _bucket =  pool.getBucket();
    if (_bucket == nullptr){
        std::cout <<"bucket is not valid\n";
        return -1;
    }

    int size = _bucket->getSize();
    std::cout<<"size: "<<size<<"\n";
    while(_bucket->push("asd",3));

    for(int i =0 ; i<2; i++){
        const char * data = _bucket->at(i);
        if(data){
            std::cout<<"data : "<<data<<"\n";
        }else{
            std::cout<<"NO DATA"<<"\n";
        }
    }

    if(!_bucket->releaseBucket()){
        std::cout <<"CHECKIN FAILED\n";
        return -1;
    }

    return  0;
}