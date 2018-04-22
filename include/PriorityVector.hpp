#ifndef H_AW_PRIORITYVECTOR
#define H_AW_PRIORITYVECTOR

#include <vector>
#include <algorithm>
#include <iterator>

namespace aw {
template <class T, class Compare>
class PriorityVector {

public:

    PriorityVector () = default;
    ~PriorityVector () = default;

    PriorityVector (PriorityVector&&) = default;
    PriorityVector& operator = (PriorityVector&&) = default;

    PriorityVector (const PriorityVector&) = default;
    PriorityVector& operator = (const PriorityVector&) = default;

    void push (T element) {

        auto iter = m_vector.begin();
        bool inserted = false;
        while (iter != m_vector.end()) {
            if (Compare(element, m_vector.at(iter))) {
                m_vector.insert(iter, element);
                inserted = true;
                break;
            }
            std::next(iter);
        }
        if (!inserted) {
            m_vector.push_back(element);
        }

    }

    void refresh () {

        auto cur = m_vector.begin();
        auto next = std::next(m_vector.begin());
        while (next != m_vector.end()) {
            if (!Compare(m_vector.at(cur), m_vector.at(next))) {
                iter_swap(cur, next);
            }
            cur = std::next(cur);
            next = std::next(next);
        }

    }

    template <typename ...TArg>
    typename std::vector<T>::const_reference at (TArg&&... args) const {
        return m_vector.at(std::forward<TArg>(args)...);
    }

    template <typename ...TArg>
    typename std::vector<T>::reference at (TArg&&... args) {
        return m_vector.at(std::forward<TArg>(args)...);
    }

    typename std::vector<T>::const_reference front () const {
        return m_vector.front();
    }

    typename std::vector<T>::reference back () const {
        return m_vector.back();
    }

    template <typename ...TArg>
    const typename std::vector<T>::value_type* data (TArg&&... args) const noexcept {
        return m_vector.data(std::forward<TArg>(args)...);
    }

    template <typename ...TArg>
    typename std::vector<T>::value_type* data (TArg&&... args) noexcept {
        return m_vector.data(std::forward<TArg>(args)...);
    }

    template <typename ...TArg>
    typename std::vector<T>::iterator erase (TArg&&... args) {
        return m_vector.erase(std::forward<TArg>(args)...);
    }

    void clear () noexcept {
        m_vector.clear();
    }

    typename std::vector<T>::size_type size () const noexcept {
        return m_vector.size();
    }

    typename std::vector<T>::size_type max_size () const noexcept {
        return m_vector.max_size();
    }

    template <typename ...TArg>
    void reserve (TArg&&... args) {
        m_vector.reserve(std::forward<TArg>(args)...);
    }

    template <typename ...TArg>
    void resize (TArg&&... args) {
        m_vector.resize(std::forward<TArg>(args)...);
    }

    typename std::vector<T>::size_type capacity () const noexcept {
        return m_vector.capacity();
    }

    bool empty () const noexcept {
        return m_vector.empty();
    }

    void shrink_to_fit () {
        m_vector.shrink_to_fit();
    }

    typename std::vector<T>::const_iterator begin () const noexcept {
        return m_vector.begin();
    }

    typename std::vector<T>::iterator begin () noexcept {
        return m_vector.begin();
    }

    typename std::vector<T>::const_iterator end () const noexcept {
        return m_vector.end();
    }

    typename std::vector<T>::iterator end () noexcept {
        return m_vector.end();
    }

    typename std::vector<T>::const_iterator rbegin () const noexcept {
        return m_vector.rbegin();
    }

    typename std::vector<T>::iterator rbegin () noexcept {
        return m_vector.rbegin();
    }

    typename std::vector<T>::const_iterator rend () const noexcept {
        return m_vector.rend();
    }

    typename std::vector<T>::iterator rend () noexcept {
        return m_vector.rend();
    }

    typename std::vector<T>::const_iterator cbegin () const noexcept {
        return m_vector.cbegin();
    }

    typename std::vector<T>::const_iterator cend () const noexcept {
        return m_vector.cend();
    }

    typename std::vector<T>::const_iterator crbegin () const noexcept {
        return m_vector.crbegin();
    }

    typename std::vector<T>::const_iterator crend () const noexcept {
        return m_vector.crend();
    }

    template <typename TArg>
    typename std::vector<T>::const_reference operator [] (TArg&& arg) const {
        return m_vector[std::forward<TArg>(arg)];
    }

    template <typename TArg>
    typename std::vector<T>::reference operator [] (TArg&& arg) {
        return m_vector[std::forward<TArg>(arg)];
    }

private:

    std::vector<T> m_vector;

};
}

#endif
