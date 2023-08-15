#include <vector>
#include <vector>

template<typename T>
class BasicChar {

    public:
    
    BasicChar(const size_t s)
    :m_size(s)
    {
        m_data.reserve(s);
    }

    BasicChar<T>& operator+=(BasicChar<T>& rhs) {
        m_data.insert(m_data.begin(), rhs.m_data.end(), rhs.m_data.begin());
        m_size += rhs.size();
        return *this;
    }

    const T& operator[](size_t pos) const noexcept {
        return m_data[pos];
    }

    T& operator[](size_t pos) {
        return m_data[pos];
    }

    const size_t size() const noexcept {return m_size;}

    private:
    size_t m_size;
    std::vector<T> m_data;
};