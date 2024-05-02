import random

# TODO: to be replaced by something better like pyotp: 'pip install pyotp'
def generateOtp(): 
    otp = ''
    for i in range(6):
        otp += str(random.randint(1, 9))
    return otp
