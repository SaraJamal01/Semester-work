from statemachine import StateMachine, State

class FSM(StateMachine):
    s0 = State('s0', initial=True)
    s1 = State('s1')                    # State machine for all strings ending with b

    a = s0.to(s0) | s1.to(s0) 
    b = s0.to(s1) | s1.to(s1) 

word = input("Enter string: ")
m = FSM()

for c in word:
    m.run(c)
if m.is_s1 :
    print("String accepted")
else:
    print("String rejected")
