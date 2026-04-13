#include "Product.h"
#include <vector>
#include <optional>

class Inventory
{
private:
    std::vector<Product> products;

public:
    void addProduct(const Product &p);
    void removeByName(const std::string &name);
    std::vector<Product> filterByCategory(const std::string &category) const;
    std::vector<Product> filterByPrice(double min, double max) const;
    double totalInventoryValue() const;
    void sortByPrice();
    std::optional<Product> findCheapest() const;
    void print() const;

    explicit operator bool() const;
};