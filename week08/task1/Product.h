#include <string>
#include <compare>
#include <ostream>

class Product
{
private:
    std::string name;
    std::string category;
    double price;
    int quantity;

public:
    Product(std::string name_, std::string category_, double price_, int quantity_);

    const std::string &getName() const;
    const std::string &getCategory() const;
    double getPrice() const;
    int getQuantity() const;

    double totalValue() const;

    bool operator==(const Product &other) const;

    std::partial_ordering operator<=>(const Product &other) const
    {
        if (auto cmp = price <=> other.price; cmp != 0)
        {
            return cmp;
        }
        return std::compare_partial_order_fallback(name, other.name);
    }

    friend std::ostream &operator<<(std::ostream &, const Product &);
};