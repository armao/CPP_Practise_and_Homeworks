#include <iostream>
#include <ratio>
#include <type_traits>

template <typename Metric>
struct metric_length
{
public:
    metric_length(int value)
        : m_value(value)
    {
    }

    template<typename OtherMetric>
    auto operator+(const metric_length<OtherMetric>& other) const
    {
        int my_value = m_value;
        int other_value = other.m_value;

        using UnionMetric = std::conditional_t<(Metric::num - Metric::den <= OtherMetric::num - OtherMetric::den), Metric, OtherMetric>;

        if ((Metric::num - Metric::den) > (OtherMetric::num - OtherMetric::den))
        {
            my_value *= Metric::num * (OtherMetric::den / Metric::den);
        }
        else if ((Metric::num - Metric::den) < (OtherMetric::num - OtherMetric::den))
        {
            other_value *= OtherMetric::num * (Metric::den / OtherMetric::den);
        }

        int result_value = my_value + other_value;

        return metric_length<UnionMetric>(result_value);
    }

    template<typename OtherMetric>
    auto operator-(const metric_length<OtherMetric>& other) const
    {
        int my_value = m_value;
        int other_value = other.m_value;

        using UnionMetric = std::conditional_t<(Metric::num - Metric::den <= OtherMetric::num - OtherMetric::den), Metric, OtherMetric>;

        if ((Metric::num - Metric::den) > (OtherMetric::num - OtherMetric::den))
        {
            my_value *= Metric::num * OtherMetric::den;
        }
        else if ((Metric::num - Metric::den) < (OtherMetric::num - OtherMetric::den))
        {
            other_value *= OtherMetric::num * Metric::den;
        }

        int result_value = my_value - other_value;

        return metric_length<UnionMetric>(result_value);
    }

public:
    int m_value;
};

template <typename Metric>
std::ostream& operator<<(std::ostream& os, const metric_length<Metric>& ml)
{
    os << ml.m_value;
    return os;
}

int main(int argc, char* argv[])
{
    using meters = metric_length<std::ratio<1, 1>>;
    using centimeters = metric_length<std::ratio<1, 100>>;
    using kilometers = metric_length<std::ratio<1000, 1>>;
    using millimetres = metric_length<std::ratio<1, 1000>>;

    meters m{ 1 };
    centimeters cm{ 50 };
    kilometers km{ 5 };
    millimetres mm{ 9 };

    std::cout << m << std::endl;

    std::cout << km + m << std::endl;
    std::cout << cm + m << std::endl;

    std::cout << km - m << std::endl;
    std::cout << m - cm << std::endl;

    std::cout << mm + cm  << std::endl;
    std::cout << m - mm + mm - mm + m << std::endl;
    std::cout << cm + m + mm + km << std::endl;

    return 0;
}
