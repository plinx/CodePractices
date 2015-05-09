__author__ = 'linx'

import unittest
from chapter2.R import Reinforcement

class cpt2(unittest.TestCase):
    # R2.4 test
    def test_Flower(self):
        f = Reinforcement.Flower("sakura", 5, 0)
        f.changeName("narcissus")
        f.changePrice(8)

        self.assertEqual(f.getName(), "narcissus")
        self.assertEqual(f.getPetal(), 5)
        self.assertEqual(f.getPrice(), 8)

    # R2.5 - 2.6
    def test_CreditCard(self):
        cc = Reinforcement.CreditCard("A", "bank", "123456", 100, 5.2)
        #cc.charge(5.2)
        self.assertEqual(cc.make_payment("s"), False)
        self.assertEqual(cc.make_payment(1), True)
        self.assertEqual(cc.get_balance(), 4.2)
        self.assertEqual(cc.make_payment(1.1), True)
        self.assertEqual(cc.get_balance(), 3.1)
        #cc.make_payment(-1)


if __name__ == '__main__':
    unittest.main()
