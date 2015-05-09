#!/usr/bin/env python
# -*- coding : utf-8 -*-

# import packages
import unittest
from inc.test import Test
from chapter4.C import Creativity


def main():
    c = Creativity()
    table = [1, 2]
    c.subsets(table)

if __name__ == '__main__':
    main()

