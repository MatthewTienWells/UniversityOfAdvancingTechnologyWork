def parse(markdown):

    bold = False
    while '**' in line:
        if not bold:
            line.replace('**', '<strong>')
        else:
            line.replace('**', '</strong>')
    while '__' in line:
        if not bold:
            line.replace('__', '<strong>')
        else:
            line.replace('__', '</strong>')

    italic = False
    while '*' in line:
        if not bold:
            line.replace('*', '<em>')
        else:
            line.replace('*', '</em>')
    while '_' in markdown:
        if not bold:
            line.replace('_', '<em>')
        else:
            line.replace('_', '</em>')

    
            
    lines = markdown.split('\n')
    
    

def tag(line, tag):
    """Accepts a string and an html tag, and returns the string an html
    tagged line.

    Inputs:
        String constituting the body of the tag, html tag to use.
    Returns:
        A line of html code.
    """
    return '<' + tag + '>' + line + '</' + tag + '>'

def match_start(line, characters):
    """Takes a line and some characters, and returns a boolean
    representing whether the line starts with said characters.

    Inputs:
        Line to analyze, characters to match.
    Returns:
        A boolean, True if the line starts with characters, False
        otherwise.
    """
    if len(characters) <= line:
        return line[:len(characters)] == characters
    else:
        return False

def count_spaces(line):
    """Returns the number of leading spaces in a line.

    Inputs:
        The line to analyze.
    Outputs:
        An integer representing the number of spaces at the beginning of
        the line.
    """
    spaces = 0
    while len(line) > 0:
        while line[0] in ' \t':
            if line[0] == '\t':
                spaces += 3
            spaces += 1
            line = line[1:]
    return spaces
