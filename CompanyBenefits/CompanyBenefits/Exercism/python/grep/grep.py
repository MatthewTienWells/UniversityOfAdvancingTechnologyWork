def grep(pattern, flags, files):
    flags = flags.split(' ')
    to_print = ''
    if '-i' in flags:
        pattern = pattern.lower()
    for file in files:
        ofile = open(file)
        line_number = 0
        printed_name = False
        data = ofile.read()
        parsed = data.split('\n')
        for line in parsed:
            line_number += 1
            match = False
            case_line = line
            if '-i' in flags:
                line = line.lower()
            if pattern in line and '-x' not in flags:
                match = True
            elif pattern == line and '-x' in flags:
                match = True
            if '-v' in flags:
                match = not match
            if match:
                if '-l' not in flags:
                    if len(files) > 1:
                        to_print += ofile.name
                        printed_name = True
                        to_print += ':'
                    if '-n' in flags:
                        to_print += str(line_number) + ':'
                    to_print += case_line + '\n'
                elif not printed_name:
                    to_print += ofile.name
                    printed_name = True
                    to_print += '\n'
    return to_print
            
