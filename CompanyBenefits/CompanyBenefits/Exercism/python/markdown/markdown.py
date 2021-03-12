"""This module provides tools for the processsing of markdown scripts
into HTML scripts. It supports lists, italicization, and bolding.
It is assumed that inputs provided are valid markdown scripts. Call
'parse' with the markdown script to run all functions in proper order.
"""

def list_test(line):
    """Returns True if the line is a top-level entry in an unordered
    list (begins with '* '), False otherwise.

    Inputs:
        Line to evaluate.
    Outputs:
        A boolean.
    """
    if len(line) > 1:
        return line[:2] == '* '
    else:
        return False

def sublist_test(line):
    """Returns True if the line is a non-top-level entry in an unordered
    list (indented, begins with '* '), False otherwise.

    Inputs:
        Line to evaluate.
    Outputs:
        A boolean.
    """
    if len(line) > 0:
        if line[0] != ' ':
            return False
        line.strip(' ')
    else:
        return False
    return list_test(line)

def ordered_list_test(line):
    """Returns True if the line is a top-level entry in an ordered list
    (begins with '1. '), False otherwise.

    Inputs:
        Line to evaluate.
    Outputs:
        A boolean.
    """
    if len(line) > 2:
        return line[:3] == '1. '
    else:
        return False

def ordered_sublist_test(line):
    """Returns True if the line is a non-top-level entry in an ordered
    list (indented, begins with '1. '), False otherwise.

    Inputs:
        Line to evaluate.
    Outputs:
        A boolean.
    """
    if len(line) > 0:
        if line[0] != ' ':
            return False
        line.strip(' ')
    else:
        return False
    return ordered_list_test(line)

def header_one(line):
    """Returns True if the line is a header 1 (begins with '# '),
    False otherwise.

    Inputs:
        Line to evaluate.
    Outputs:
        A boolean.
    """
    if len(line) > 1:
        return line[:2] == '# '
    else:
        return False

def header_two(line):
    """Returns True if the line is a header 2 (begins with '## '),
    False otherwise.

    Inputs:
        Line to evaluate.
    Outputs:
        A boolean.
    """
    if len(line) > 2:
        return line[:3] == '## '
    else:
        return False

def header_six(line):
    """Returns True if the line is a header 6 (begins with '###### '),
    False otherwise.

    Inputs:
        Line to evaluate.
    Outputs:
        A boolean.
    """
    if len(line) > 6:
        return line[:7] == '###### '
    else:
        return False

def start_emphasis(line):
    """Replaces opening emphasis marks in the provided line with '<em>'.

    Inputs:
        A line to process.
    Outputs:
        The processed line.
    """
    
    if len(line) > 2:
        for num in range(1, len(line)-1):
            if (line[num-1] == ' ' and
            (line[num] == '_' or line[num] == '*') and
            line[num+1] != ' '):
                line = line[:num] + '<em>' + line[num+1:]
        if (line[0] == '*' or line[0] == '_') and line[1] != ' ':
            line = '<em>' + line[1:]
    return line
        
def end_emphasis(line):
    """Replaces closing emphasis marks in the provided line with '</em>'.

    Inputs:
        A line to process.
    Outputs:
        The processed line.
    """
    if len(line) > 2:
        for num in range(1, len(line)-1):
            if (line[num-1] != ' ' and
            (line[num] == '_' or line[num] == '*') and
            line[num+1] == ' '):
                line = line[:num] + '</em>' + line[num+1:]
        if (line[-1] == '*' or line[-1] == '_') and line[-2] != ' ':
            line = line[:-1] + '</em>'
    return line
        
def start_strong(line):
    """Replaces opening strong marks in the provided line with '<strong>'.

    Inputs:
        A line to process.
    Outputs:
        The processed line.
    """
    while ' **' in line:
        line = line.replace(' **', ' <strong>')
    while ' __' in line:
        line = line.replace(' __', ' <strong>')
    if len(line) > 2:
        if line[:2] == '**' or line[:2] == '__':
            line = '<strong>' + line[2:]
    return line
        
def end_strong(line):
    """Replaces closing strong marks in the provided line with '</strong>'.

    Inputs:
        A line to process.
    Outputs:
        The processed line.
    """
    while '__ ' in line:
        line = line.replace('__ ', '</strong> ')
    while '** ' in line:
        line = line.replace('** ', ' </strong>')
    if len(line) > 2:
        if line[-2:] == '**' or line[-2:] == '__':
            line = line[:-2] + '</strong>'
    return line
        
def tag(line, markdown_tag, html_tag):
    """Accepts a string and an html tag, and returns the string as an
    html tagged line with proper italicization and bolding.

    Inputs:
        String constituting the body of the tag, list containing the
        characters to replace and the html tag to use.
    Returns:
        A line of html code.
    """
    transforms = [start_strong, end_strong, start_emphasis, end_emphasis]
    line = line[len(markdown_tag):]
    for transform in transforms:
        line = transform(line)
    return '<' + html_tag + '>' + line + '</' + html_tag + '>'

line_types = {
    list_test:['* ', 'li'],
    sublist_test:['* ', 'li'],
    ordered_list_test:['1. ', 'li'],
    ordered_sublist_test:['1. ', 'li'],
    header_one:['# ', 'h1'],
    header_two:['## ', 'h2'],
    header_six:['###### ', 'h6']
    }

def parse(markdown):
    """Takes a markdown script and converts it to an HTML script.

    Script is broken into lines, and for each line:
    * A start or end list tag is added, if appropriate.
    * The line is tested for a header or list type.
    * If no type is found, it is treated as a paragraph.
    * The line is passed to the tag function, which strips line IDs.
    * The tag function also replaces markdown bold and
        italics with HTML, and adds the appropriate tag to the
        whole line.
    * Each line is added to a string of HTML code when processed.
    * When all lines are processed, end tags are added for any open
        lists.

    Inputs:
        A string representing a markdown script.
    Outputs:
        A string representing an HTML script.
    """
    lines = markdown.split('\n')
    o_list = False
    u_list = False
    so_list = False
    su_list = False
    html = ''
    for line in lines:
        
        if not o_list and ordered_list_test(line):
            html += '<ol>'
            o_list = True
        if not u_list and list_test(line):
            html += '<ul>'
            u_list = True
        if not so_list and ordered_sublist_test(line):
            html += '<ol>'
            so_list = True
        if not su_list and sublist_test(line):
            html += '<ul>'
            su_list = True

        if o_list and not ordered_list_test(line):
            html += '</ol>'
            o_list = False
        if u_list and not list_test(line):
            html += '</ul>'
            u_list = False
        if so_list and not ordered_sublist_test(line):
            html += '</ol>'
            so_list = False
        if su_list and not sublist_test(line):
            html += '</ul>'
            su_list = False
        
        paragraph = True
        for key in line_types:
            if key(line):
                paragraph = False
                if su_list or so_list:
                    while line[0] == ' ':
                        line = line[1:]
                line = tag(line, *line_types[key])
        if paragraph:
            line = tag(line, '', 'p')
            
        html += line
    if su_list:
        html += '</ul>'
    if so_list:
        html += '</ol>'
    if u_list:
        html += '</ul>'
    if o_list:
        html += '</ol>'

    return html
