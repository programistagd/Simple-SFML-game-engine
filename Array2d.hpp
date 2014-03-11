/* 
 * File:   Array2d.hpp
 * Author: radek
 *
 * Created on 10 marzec 2014, 21:19
 */

#ifndef ARRAY2D_HPP
#define	ARRAY2D_HPP

/*template<class T> struct Array2d{
    Array2d(unsigned int n)
    :size(n)
    {
        assert(n>0);
        data = new T[n*n];
    }
    inline T& get(unsigned int x, unsigned int y){
        return data[x+y*size];
    }
    Array2d(const Array2d& other){
        size = other.size;
        data = new T[size*size];
        for(unsigned int i=0;i<size*size;i++){
            data[i]=other.data[i];
        }
    }
    ~Array2d(){
        delete [] data;
    }
private:
    T* data;
    unsigned int size;
};*/

template<class T, int N> struct Array2d{
    Array2d()
    {
        assert(N>0);
        data = new T[N*N];
    }
    inline T& get(unsigned int x, unsigned int y){
        assert(x>=0 && x<N && y>=0 && y<N);
        return data[x+y*N];
    }
    inline T& get(unsigned int x, unsigned int y) const{
        assert(x>=0 && x<N && y>=0 && y<N);
        return data[x+y*N];
    }
    inline bool areAllNull(){
        for(unsigned int i=0;i<N;i++)
            if(data[i]!=nullptr) return false;
        return true;
    }
    Array2d(const Array2d& other){
        data = new T[N*N];
        for(unsigned int i=0;i<N*N;i++){
            data[i]=other.data[i];
        }
    }
    ~Array2d(){
        delete [] data;
    }
private:
    T* data;
};

template <typename T, int S> struct Array{
    T data[S];
    T& operator[](unsigned int i){
        assert(i<S);
        return data[i];
    }
    T& operator[](unsigned int i) const{
        assert(i<S);
        return data[i];
    }
    Array(){}
    Array(T data[S]):data(data){}
};

#endif	/* ARRAY2D_HPP */

