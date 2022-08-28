#ifndef DISTANCE_H
#define DISTANCE_H

#include <iterator>

namespace exo {

    namespace detail {

        template <typename Iterator>
        constexpr typename std::iterator_traits<Iterator>::difference_type 
        distance_impl(Iterator first, Iterator last, std::input_iterator_tag) 
        {
            typename std::iterator_traits<Iterator>::difference_type result = 0;
            while(first != last) {
                ++first;
                ++result;
            }
            return result;
        }

        template <typename Iterator>
        constexpr typename std::iterator_traits<Iterator>::difference_type 
        distance_impl(Iterator first, Iterator last, std::random_access_iterator_tag) 
        {
            return last - first;
        }

    }

    template<typename Iterator>
    constexpr typename std::iterator_traits<Iterator>::difference_type distance(Iterator first, Iterator last) 
    {
        using category = typename std::iterator_traits<Iterator>::iterator_category;
        return detail::distance_impl(first, last, category());
    }
}


#endif