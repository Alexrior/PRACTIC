import requests

def get_weather(city):
    api_key = "ВАШ_API_KEY"  # Получите на openweathermap.org
    url = f"http://api.openweathermap.org{city}&appid={api_key}&units=metric&lang=ru"
    
    response = requests.get(url)
    if response.status_code == 200:
        data = response.json()
        
        # Извлекаем характеристики
        temp = data['main']['temp']
        feels_like = data['main']['feels_like']
        pressure_hpa = data['main']['pressure']
        # Перевод ГПа в мм рт. ст. (коэффициент 0.75006)
        pressure_mm = int(pressure_hpa * 0.75006)
        humidity = data['main']['humidity']
        description = data['weather'][0]['description']
        wind_speed = data['wind']['speed']
        
        # Вывод
        print(f"\nПогода в городе {city.capitalize()}:")
        print(f"• Температура: {temp}°C")
        print(f"• Как ощущается: {feels_like}°C")
        print(f"• Ветер: {wind_speed} м/с")
        print(f"• Давление: {pressure_mm} мм рт. ст.")
        print(f"• Влажность: {humidity}%")
        print(f"• Состояние: {description.capitalize()}")
    else:
        print("Город не найден или ошибка API.")

city_input = input("Введите название города: ")
get_weather(city_input)
