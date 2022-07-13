import random
import re
import sys


class LabTest:
    def __init__(self, test_path=''):
        self.filename = 'lab1.py'
        self.test_path = test_path
        self.test_globals = {'__name__': '__main__', '__builtins__': {'print': self.print, 'input': self.input, 'int': int, 'float': float, 'bool': bool, 'str': str, 'pow': pow}}
        self.results = {}
        self.current_output = []
        self.input_values = []
        self.current_input_temp = 0
        self.test_number = 0

    def print(self, *args, **kwargs):
        if 'sep' not in kwargs:
            kwargs['sep'] = ' '
        if 'end' not in kwargs:
            kwargs['end'] = '\n'
        # print(args)

        if isinstance(args, tuple) or isinstance(args, list):
            self.current_output.append(kwargs['sep'].join([str(x) for x in args]) + kwargs['end'])
        elif isinstance(args, str):
            self.current_output.append(args + kwargs['end'])

    def input(self, prompt):
        if isinstance(prompt, str):
            return str(self.current_input_temp)
        else:
            raise ValueError('Prompt in input statement must be a string.')

    def run_tests(self, num_tests=100):
        test_list = [32, 212] + [random.randint(-300, 500) for _ in range(num_tests - 2)]
        for i, test_temperature in enumerate(test_list):
            self.test_number = i + 1
            self.current_output = []
            self.run_test(test_temperature)

    def run_test(self, input_temp):
        self.current_input_temp = input_temp

        try:
            with open(self.filename) as lab_1_file:
                lab_one_code = lab_1_file.read()
                temp_locals = {}
                try:
                    test_passed = False
                    exec(lab_one_code, self.test_globals, temp_locals)
                    celsius = (5 / 9) * (self.current_input_temp - 32)

                    for line in self.current_output:
                        match = re.match(r".*?(?P<first_number>[-]?\d+([.]\d+)?).*?(?P<second_number>[-]?\d+([.]\d+)?).*?", line)
                        if match:
                            if self.is_close(float(match.group('first_number')), celsius) and self.is_close(float(match.group('second_number')), self.current_input_temp):
                                test_passed = True
                            if self.is_close(float(match.group('first_number')), self.current_input_temp) and self.is_close(float(match.group('second_number')), celsius):
                                test_passed = True
                    if test_passed:
                        print('Test', self.test_number, 'passed', '\t\t(input: ', self.current_input_temp, 'output:', celsius, ')')
                    else:
                        print('Test', self.test_number, 'failed', '\t\t(input: ', self.current_input_temp, 'output:', celsius, ')')

                except Exception as exc:
                    print('Test: ', self.test_number, 'Exception Thrown', str(exc))
        except OSError:
            print('File', self.filename, 'could not be found or opened.  ')

    @staticmethod
    def is_close(x, y, error=0.01):
        return abs(x - y) < error


if __name__ == '__main__':
    num_tests = 100
    try:
        if len(sys.argv) > 1:
            num_tests = int(sys.argv[1])
            if num_tests < 2:
                num_tests = 2
            if num_tests > 1000:
                num_tests = 1000
    except ValueError:
        print('That wasn\'t an integer, you\'re mean')
    lab_test = LabTest()
    lab_test.run_tests(num_tests)
