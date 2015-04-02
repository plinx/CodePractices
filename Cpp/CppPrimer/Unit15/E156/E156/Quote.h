#ifndef QUOTE_H
#define QUOTE_H

class Quote {
	Quote() = default;
	Quote(const std::string &b, double p) :
		bookNo(b), price(p) {}

	virtual double net_price(std::size_t n) const
	{
		return n * price;
	}
	virtual ~Quote() = default;

private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Bulk_quote : public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &b, double p, std::size_t sz, double d) :
		Quote(b, p), min_qty(sz), discount(d) {}
	double net_price(std::size_t) const override;

private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

#endif