#ifndef SETLIST_HPP
#define SETLIST_HPP

#include <algorithm>
#include <functional>
#include <iterator>
#include <memory>
#include <ranges>

template <typename T>
class SetList {
    struct ListNode {
        T data;
        std::shared_ptr<ListNode> next;
    };

public:
    class ListIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        explicit ListIterator(std::shared_ptr<ListNode> ptr = nullptr) : ptr(ptr) {}

        ListIterator& operator++() {
            ptr = ptr->next;
            return *this;
        }

        ListIterator operator++(int) {
            ListIterator tmp = *this;
            ptr = ptr->next;
            return tmp;
        }

        T& operator*() const {
            return ptr->data;
        }

        T* operator->() const {
            return &ptr->data;
        }

        bool operator==(const ListIterator& other) const = default;

    private:
        std::shared_ptr<ListNode> ptr;
    };

    using value_type = T;
    using iterator = ListIterator;

    SetList() = default;

    template <std::ranges::input_range Rng>
    explicit SetList(Rng&& rng) {
        std::ranges::for_each(std::forward<Rng>(rng), std::bind_front(&SetList::insert, this));
    }

    ListIterator begin() {
        return ListIterator{head};
    }

    ListIterator end() {
        return ListIterator{nullptr};
    }

    bool contains(const T& value) {
        for (auto it = begin(); it != end(); ++it) {
            if (*it == value) {
                return true;
            }
        }
        return false;
    }

    ListIterator insert(T value) {
        if (!contains(value)) {
            auto newNode = std::make_shared<ListNode>();
            newNode->data = std::move(value);
            newNode->next = head;
            head = newNode;
        }
        return ListIterator{head};
    }

private:
    std::shared_ptr<ListNode> head = nullptr;
};

#endif

