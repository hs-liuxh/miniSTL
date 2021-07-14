#ifndef MINI_VECTOR_H_
#define MINI_VECTOR_H_


#include <initializer_list>

#include "iterator.h"
#include "memory.h"
#include "util.h"
#include "exceptdef.h"
// 总计依赖 9个 .h

namespace mystl
{

#ifdef max
#pragma message("#undefing macro max")
#undef max
#endif

#ifdef min
#pragma message("undefing macro min")
#undef min
#endif


template <class T>
class vector
{
    static_assert(!std::is_same<bool, T>::value, "vector<bool> is non-supported in mystl");

public:
    // 本类的嵌套类型
    typedef mystl::allocator<T>                         allocator_type;
    typedef mystl::allocator<T>                         data_allocator;

    // 其他类的嵌套类型
    typedef typename allocator_type::value_type         value_type;
    typedef typename allocator_type::pointer            pointer;
    typedef typename allocator_type::const_pointer      const_pointer;
    typedef typename allocator_type::reference          reference;
    typedef typename allocator_type::const_reference    const_reference;
    typedef typename allocator_type::size_type          size_type;
    typedef typename allocator_type::difference_type    difference_type;

    typedef value_type*                                 iterator;
    typedef const value_type*                           const_iterator;
    typedef mystl::reverse_iterator<iterator>           reverse_iterator;
    typedef mystl::reverse_iterator<const_iterator>     const_reverse_iterator;

    allocator_type get_allocator() { return data_allocator(); };

private:
    iterator begin_;    // 当前使用空间的头部
    iterator end_;      // 当前使用空间的尾部
    iterator cap_;      // 当前可用空间的尾部

public:
    vector() noexcept { try_init(); }

    explicit vector(size_type n) { }


private:
    // helper functions: 6 types

    // initialize / destroy
    void try_init() noexcept;
    void fill_init(size_type n, const value_type& value);

    void init_space(size_type size, size_type cap);




    // calculate the growth size



    // assign



    // reallocate


    // insert


    // shrink_to_fit

};


/*****************************************************************************************/
// helper function

// try_init: 分配默认容量，若分配失败则忽略，不抛出异常
template <class T>
void vector<T>::try_init() noexcept
{
    try
    {
        begin_ = data_allocator::allocate(16);
        end_ = begin_;
        cap_ = begin_ + 16;
    }
    catch(...)
    {
        begin_ = nullptr;
        end_ = nullptr;
        cap_ = nullptr;
    }
    
}
// init_space: 分配指定容量，若分配失败则抛出异常
template <class T>
void vector<T>::init_space(size_type size, size_type cap)
{
    try
    {
        begin_ = data_allocator::allocator(cap);
        end_ = begin_ + size;
        cap_ = begin_ + cap;
    }
    catch(const std::exception& e)
    {
        begin_ = nullptr;
        end_ = nullptr;
        cap_ = nullptr;
    }
    
}

template<class T>
void vector<T>::fill_init(size_type n, const value_type& value)
{
    const size_type init_size = mystl::max(static_cast<size_type>(16), n);
    init_space(n, init_size);
    mystl::uninitialized_fill_n(begin_, n, value);
}




}; // namespace mystl










#endif