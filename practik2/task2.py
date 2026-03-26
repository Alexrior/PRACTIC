import re

def extract_emails(text):
    # Описание шаблона:
    # [a-zA-Z0-9+_#-] — разрешенные символы до собаки
    # + — один или более таких символов
    # @ — обязательный символ собаки
    # [a-zA-Z0-9.-]+ — домен (буквы, цифры, точки и дефисы)
    # \.[a-zA-Z]{2,} — точка и домен верхнего уровня (минимум 2 буквы)
    pattern = r'[a-zA-Z0-9+_#-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}'
    
    emails = re.findall(pattern, text)
    
    for email in emails:
        print(email)

# Пример работы
sample_input = "Jones and Palin met at Oxford University, where they performed together ysinghmanga@206954.com with the Oxford Revue. (6boutheina+14@weammo.xyz)"
extract_emails(sample_input)
