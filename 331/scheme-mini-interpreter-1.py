import re
#this Python code runs in Python 3

#program = "(cdr(list 1 2 (list 4 (list 5 6)) (list 7 8)))"
#program = '(list 1 2 (list 3 4))'
#program = '(list 1 2)'

op_order_stack = []
scheme_string = ''

def split_all(program):
    program = program.replace('(', ' ( ')
    program = program.replace(')', ' ) ')
    all_tokens = program.split()
    #print("Debug: split_all() returns ", all_tokens)
    return all_tokens

def tokenize(all_tokens):
    global op_order_stack
    token = all_tokens.pop(0)
    if (token == '('):
        stack = []
        while (all_tokens[0] != ')'):
            stack.append(tokenize(all_tokens))
        all_tokens.pop(0)
        #print("Debug: tokenize() returns ", stack)
        return stack
    else:
        if (not token.isdigit()):
            op_order_stack.append(token)
        return token
                
def evaluate(stack):
    global op_order_stack
    global scheme_string
    symbol = ''
    if type(stack) is list:
        symbol = stack.pop(0)
        if (symbol == 'cdr'):
            argument = evaluate(stack.pop(0))
            result = argument[1:]
            op_order_stack.pop()
            if (len(op_order_stack) == 0):
                format_scheme_list(result)
                print(scheme_string)
            #print("Debug: evaluate() cdr returns ",result)
            return result
        elif (symbol == 'list'):
            result = []
            for x in range(len(stack)):
                result.append(evaluate(stack.pop(0)))
            op_order_stack.pop()
            if (len(op_order_stack) == 0):
                format_scheme_list(result)
                print(scheme_string)
            #print("Debug: evaluate() list returns ", result)
            return result
        else:
            print('An error happened at {0}'.format(stack))
            return
    elif (stack.isdigit()):
        symbol = stack
        #print("Debug: evaluate() digit returns ", symbol)
        return symbol
    else:
        print('An error happened at {0}'.format(stack))
        return
    
def format_scheme_list(python_list):
    global scheme_string
    scheme_string += '('
    for x in python_list:
        if (type(x) is list):
            format_scheme_list(x)
        else:
            scheme_string += ' ' + x + ' '
    scheme_string += ')'


stop = False
while(not stop):
    inputstring = input("Tiny Scheme Interpreter >>> ")
    if (inputstring == ''):
        pass
    elif (not re.findall('\(\s*exit\s*\)', inputstring)):
        op_order_stack = []
        scheme_string = ''
        evaluate(tokenize(split_all(inputstring)))
    else:
        stop = True
