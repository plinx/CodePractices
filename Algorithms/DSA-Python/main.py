#!/usr/bin/env python
# -*- coding : utf-8 -*-

# import packages
import unittest
from inc.test import Test
from chapter1.P import Project
from chapter3.R import Reinforcement


def main():
    r = Reinforcement()
    print r.cmp1()

if __name__ == '__main__':
    main()

