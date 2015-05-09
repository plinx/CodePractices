__author__ = 'linx'

class Reinforcement(object):
    # R2.1
    # Windows, Chrome, QQ

    # R2.2-2.3
    # skip

    # R2.4
    class Flower(object):
        def __init__(self, name, petal, price):
            self._name = name
            self._petal = petal
            self._price = price

        def changeName(self, name):
            self._name = name

        def changePetal(self, petal):
            self._petal = petal

        def changePrice(self, price):
            self._price = price

        def getName(self):
            return self._name

        def getPetal(self):
            return self._petal

        def getPrice(self):
            return self._price

    # R2.5 - 2.7
    class CreditCard(object):
        def __init__(self, customer, bank, account, limit, balance):
            self._customer = customer
            self._bank = bank
            self._account = account
            self._limit = limit
            self._balance = balance

        def get_customer(self):
            return self._customer

        def get_bank(self):
            return self._bank

        def get_limit(self):
            return self._limit

        def get_balance(self):
            return self._balance

        def charge(self, price):
            if price + self._balance > self._limit:
                return False
            else:
                self._balance += price
                return True

        def make_payment(self, amount):
            if type(amount) == float or type(amount) == int:
                if amount < 0:
                    print "negative"
                    raise ValueError("Negative value is sent")
                else:
                    self._balance -= amount
                    return True
            else:
                return False

    # skip the less exercises

    pass

