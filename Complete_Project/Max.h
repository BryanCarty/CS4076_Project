#ifndef MAX_H
#define MAX_H


template <class T>
class Max{
    T first, second;
    public:
        Max(T a, T b){
            first=a;
            second=b;
        }
        T bigger(){
            return (first>=second?first:second);
        }
        T smaller(){
            return (first<=second?first:second);
        }

};
#endif // MAX_H
