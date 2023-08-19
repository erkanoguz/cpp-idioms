#ifndef ANIMAL_H
#define ANIMAL_H

#include <memory>

template <typename T>
class Animal 
{
public:
    Animal(T&& object) 
        : _ptr(std::make_unique<AnimalModel<T>>(std::forward<T>(object)))
    {}

    void foo() 
    {
        _ptr->foo();
    }

private:
    class AnimalConcept
    {
    public:
        virtual ~AnimalConcept() = default;
        virtual void foo() = 0;
    };

    template <typename U>
    class AnimalModel : public AnimalConcept 
    {
    public:
        AnimalModel(const U& object) 
            : _object(object) 
        {}

        void foo() override 
        {
            return _object.foo();
        }

    private:
        U _object;
    };

    std::unique_ptr<AnimalConcept> _ptr;
};
#endif 