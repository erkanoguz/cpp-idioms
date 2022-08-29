#include <iostream>
#include <memory>

template <typename T>
class SingletonBase 
{
public:
    SingletonBase(const SingletonBase&) = delete;
    SingletonBase& operator= (const SingletonBase&) = delete;

    static T& get_instance() 
    {
        if (_instance == nullptr)
            _instance.reset(new T());

        return *_instance;
    }

protected:
    SingletonBase() {}

private:
    static inline std::unique_ptr<T> _instance{nullptr};
};

class Derived : public SingletonBase<Derived> {
public:
    Derived() {}
    ~Derived() {}
    void foo() {}
};


