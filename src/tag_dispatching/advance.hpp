#ifndef ADVANCE_HPP
#define ADVANCE_HPP

#include <iterator>

namespace exo
{

namespace detail {
template <typename Iterator, typename Distance>
void advance_impl(Iterator& iter, Distance n, std::input_iterator_tag)
{
    while(n--) {
        ++iter;
    }
}

template <typename Iterator, typename Distance>
void advance_impl(Iterator& iter, Distance n, std::random_access_iterator_tag)
{
    iter += n; // constant time
}

template <typename Iterator, typename Distance>
void advance_impl(Iterator& iter, Distance n, std::bidirectional_iterator_tag)
{
    if (n >= 0) {
        while (n--)
            ++iter;
    } else {
        while(n--) 
            --iter;
    }
}

} // detail

template <typename Iterator, typename Distance>
void  advance(Iterator& iter, Distance n)
{
    detail::advance_impl(iter, n, typename std::iterator_traits<Iterator>::iterator_category());
}

} // exo

#endif