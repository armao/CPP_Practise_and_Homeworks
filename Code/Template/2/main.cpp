#include <iostream>
#include <ratio>

template <typename Metric>
struct metric_length
{
public:
    metric_length(double value)
        : m_value(value)
    {
    }

    template<typename OtherMetric>
    auto operator+(const metric_length<OtherMetric>& other) const
    {
        using UnionMetric = std::ratio <
            ((Metric::num / Metric::den) <= (OtherMetric::num / OtherMetric::den)) ? Metric::num : OtherMetric::num,
            ((Metric::num / Metric::den) <= (OtherMetric::num / OtherMetric::den)) ? Metric::den : OtherMetric::den>;
        double my_value = m_value * Metric::num / Metric::den;
        double other_value = other.m_value * OtherMetric::num / OtherMetric::den;
        double result_value = my_value + other_value;

        return metric_length<UnionMetric>(result_value *UnionMetric::den / UnionMetric::num);
    }

    template<typename OtherMetric>
    auto operator-(const metric_length<OtherMetric>& other) const
    {
        using UnionMetric = std::ratio <
            ((Metric::num / Metric::den) <= (OtherMetric::num / OtherMetric::den)) ? Metric::num : OtherMetric::num,
            ((Metric::num / Metric::den) <= (OtherMetric::num / OtherMetric::den)) ? Metric::den : OtherMetric::den>;
        double my_value = m_value * Metric::num / Metric::den;
        double other_value = other.m_value * OtherMetric::num / OtherMetric::den;
        double result_value = my_value - other_value;

        return metric_length<UnionMetric>(result_value * UnionMetric::den / UnionMetric::num);
    }

public:
    double m_value;

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
