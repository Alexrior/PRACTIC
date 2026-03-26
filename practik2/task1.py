import re
from datetime import datetime

def find_valid_timestamps(text):
    # Регулярное выражение:
    # 20\d{2} — года 2000-2099
    # \d{2}-\d{2} — месяц и день
    # \d{2}:\d{2}:\d{2} — часы, минуты, секунды
    pattern = r'\b(20\d{2}-\d{2}-\d{2}\s\d{2}:\d{2}:\d{2})\b'
    
    found_strings = re.findall(pattern, text)
    valid_results = []

    for ts_str in found_strings:
        try:
            # Проверка на реальность даты (валидация календаря и времени)
            datetime.strptime(ts_str, '%Y-%m-%d %H:%M:%S')
            valid_results.append(ts_str)
        except ValueError:
            # Если дата некорректна (например, 2023-02-30), пропускаем
            continue
            
    return valid_results

# Пример использования:
test_text = """
Встреча назначена на 2024-05-15 10:30:00.
Ошибка в данных: 2023-02-30 12:00:00 (нет такого дня).
Старая запись: 1999-12-31 23:59:59 (не 21 век).
Будущее: 2099-12-31 23:59:59.
Неверный формат времени: 2024-01-01 25:00:00.
"""

results = find_valid_timestamps(test_text)
print("Найденные вхождения:")
for res in results:
    print(res)
