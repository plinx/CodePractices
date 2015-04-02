#ifndef QUOTE_H
#define QUOTE_H

class Quote {
public:
	Quote() = default;
	Quote(const std::string &b, double p) :
		bookNo(b), price(p) {}

	std::string isbn () const { return bookNo; }

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

class book_quote : public Bulk_quote {
public:
	book_quote() = default;
	book_quote(const std::string &s, double p, std::size_t sz, double d, std::size_t n) :
		Bulk_quote(s, p, sz, d), num(n) {}

	void get_price();

private:
	std::size_t num;
};

double Bulk_quote::net_price(std::size_t cnt) const
{
	if (cnt >= min_qty)
	{
		return cnt * (1 - discount) * price;
	}
	else
	{
		return cnt * price;
	}
}

void book_quote::get_price()
{
	std::size_t tmp = num;
	double price = 0;
	while (tmp)
	{
		price += net_price(tmp);
		--tmp;
	}

	std::cout << "Book No : " << isbn() << std::endl;
	std::cout << "Total price : " << price << std::endl;

}

void print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "Book No : " << item.isbn() << std::endl;
	os << "Sold : " << n << std::endl;
	os << "total due : " << ret << std::endl;
}

#endif