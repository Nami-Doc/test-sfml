#pragma once

namespace utility {
    template<class T> std::unique_ptr<T> make_unique(T* t) {
        return std::unique_ptr<T>(t);
    }
}
