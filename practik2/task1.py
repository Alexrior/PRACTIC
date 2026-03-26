import re
from datetime import datetime

def find_valid_timestamps(text):

    pattern = r'\b(20\d{2}-\d{2}-\d{2}\s\d{2}:\d{2}:\d{2})\b'
    
    found_strings = re.findall(pattern, text)
    valid_results = []

    for ts_str in found_strings:
        try:
            