
def get_ascii_val(num, key):

    if (num + key) > 127:
        final_val = num + key
        while(final_val > 127):
            final_val = final_val % 127 
    else:
        final_val = num + key
    
    return final_val


print(get_ascii_val(300,100))

