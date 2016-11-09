import unittest

from program import fibonacci


class TestProgram(unittest.TestCase):

    def test_fibonacci(self):
        self.assertEqual(0, fibonacci(1))
        self.assertEqual(1, fibonacci(2))
        self.assertEqual(2, fibonacci(3))
        self.assertEqual(3, fibonacci(4))
        self.assertEqual(5, fibonacci(5))
        self.assertEqual(8, fibonacci(6))
        self.assertEqual(13, fibonacci(7))
        self.assertEqual(21, fibonacci(8))
        self.assertEqual(34, fibonacci(9))
        self.assertEqual(55, fibonacci(10))


if __name__ == '__main__':
    unittest.main()
