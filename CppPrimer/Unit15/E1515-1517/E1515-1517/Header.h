class Quote {
public:
	Quote() = default;
	Quote(const std::string &b, double p) :
		bookNo(b), price(p) {}

	std::string isbn() const { return bookNo; }

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

class Disc_quote : public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string &b, double p, std::size_t q, double d) :
		Quote(b, p), quantity(q), discount(d) {}

	double net_price(std::size_t) const = 0;

protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote(const std::string &b, double p, std::size_t q, double d) :
		Disc_quote(b, p, q, d) {}
};

class book_quote : public Disc_quote {
public:
	book_quote() = default;
	book_quote(const std::string &s, double p, std::size_t q, double d, std::size_t n) :
		Disc_quote(s, p, q, d), num(n) {}

	void get_price();
	double net_price(std::size_t) const override;

private:
	std::size_t num = 0;
};

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

double book_quote::net_price(std::size_t cnt) const
{
	if (cnt >= quantity)
	{
		return cnt * (1 - discount) * price;
	}
	else
	{
		return cnt * price;
	}
}

void print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "Book No : " << item.isbn() << std::endl;
	os << "Sold : " << n << std::endl;
	os << "total due : " << ret << std::endl;
}