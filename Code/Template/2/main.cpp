#include <iostream>
#include <ratio>

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
        using UnionMetric = std::ratio_add<Metric, OtherMetric>;
        int my_value = m_value;
        int other_value = other.m_value;

        if ((Metric::num - Metric::den) > (OtherMetric::num - OtherMetric::den))
        {
            using UnionMetric = std::ratio<OtherMetric::num, OtherMetric::den>;
            my_value *= Metric::num * OtherMetric::den;
        }
        if ((Metric::num - Metric::den) < (OtherMetric::num - OtherMetric::den))
        {
            using UnionMetric = std::ratio<Metric::num, Metric::den>;
            other_value *= OtherMetric::num * Metric::den;
        }

        int result_value = my_value + other_value;

        return metric_length<UnionMetric>(result_value);
    }

    template<typename OtherMetric>
    auto operator-(const metric_length<OtherMetric>& other) const
    {
        using UnionMetric = std::ratio_add<Metric, OtherMetric>;
        int my_value = m_value;
        int other_value = other.m_value;

        if ((Metric::num - Metric::den) > (OtherMetric::num - OtherMetric::den))
        {
            using UnionMetric = std::ratio<OtherMetric::num, OtherMetric::den>;
            my_value *= Metric::num * OtherMetric::den;
        }
        if ((Metric::num - Metric::den) < (OtherMetric::num - OtherMetric::den))
        {
            using UnionMetric = std::ratio<Metric::num, Metric::den>;
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

    meters m{ 16 };
    centimeters cm{ 109 };
    kilometers km{ 12 };

    std::cout << m << std::endl;

    std::cout << km + m << std::endl;
    std::cout << cm + m << std::endl;

    std::cout << km - m << std::endl;
    std::cout << m - cm << std::endl;

    return 0;
}
