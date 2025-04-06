template < typename T, typename Comp = std::less< T > >
class sparse_table {
private:
    std::vector< T > data;
    std::vector < std::vector < size_t > > table;
    void build_table();
    inline static unsigned mlog(size_t _n);
public:
    const size_t size() const { return data.size(); }
    sparse_table(const std::vector< T >& _data) : data(_data) {
        build_table();
    }
    template < typename ItT >
    sparse_table(ItT begin, ItT end) {
        while (begin != end) {
            data.push_back(*begin);
            ++begin;
        }
        build_table();
    }
    
    const T& get_min(const size_t L, const size_t R) const;
};

template < typename T, typename Comp >
void sparse_table< T, Comp >::build_table() {
    if (!data.size()) {
        throw std::invalid_argument("Empty set is passet as a parameter.");
    }
    table.resize(1);
    table[0].resize(data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        table[0][i] = i;
    }
    unsigned pow = 1;
    const unsigned max_pow = mlog(data.size());
    table.resize(max_pow + 1);
    const Comp cmp;
    for (; pow <= max_pow; ++pow) {
        const size_t cur_step_len = static_cast< size_t >(1) << pow,
            prev_step_len = static_cast< size_t >(1) << (pow - 1);
        table[pow].resize(data.size() - cur_step_len + 1);
        for (int i = 0; i <= data.size() - cur_step_len; ++i) {
            table[pow][i] = cmp(data[table[pow - 1][i]], data[table[pow - 1][i + prev_step_len]]) ?
                table[pow - 1][i] : table[pow - 1][i + prev_step_len];
        }
    }
}

template < typename T, typename Comp >
inline unsigned sparse_table< T, Comp >::mlog(const size_t _n) {
    register size_t n = _n, k = 0;
    while ((static_cast< size_t >(1) << k) <= n) {
        ++k;
    }
    return k - 1;
}

template < typename T, typename Comp >
const T& sparse_table< T, Comp >::get_min(const size_t L, const size_t R) const {
    if (L > data.size() || R == 0 || R > data.size()) {
        throw std::out_of_range("Wrong index is used.");
    }
    if (L >= R) {
        throw std::invalid_argument("Wrong arguments in query.");
    }
    const unsigned pow = mlog(R - L);
    const Comp cmp;
    const size_t check_len = static_cast< size_t >(1) << pow;
    return cmp(data[table[pow][L]], data[table[pow][R - check_len]]) ?
        data[table[pow][L]] : data[table[pow][R - check_len]];
}