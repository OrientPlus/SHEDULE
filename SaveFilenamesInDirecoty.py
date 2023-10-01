import os

import os

def list_files_in_directory(directory_path, output_file_path):
    try:
        # Открываем файл для записи
        with open(output_file_path, 'w') as output_file:
            # Проходимся по файлам в указанной директории
            for root, dirs, files in os.walk(directory_path):
                for file_name in files:
                    # Получаем имя файла с расширением
                    file_with_extension = os.path.basename(file_name)
                    # Записываем имя файла в файл построчно
                    output_file.write(file_with_extension + '\n')
        print(f'Имена файлов были записаны в файл: {output_file_path}')
    except Exception as e:
        print(f'Произошла ошибка: {str(e)}')


# Укажите путь к директории, которую вы хотите просканировать
#directory_to_scan = 'C:/VCPKG/vcpkg/installed/x64-windows/lib'
directory_to_scan = input("Path to scan: ")

# Укажите путь к файлу, в который будут записаны имена файлов
output_file_path = 'имена_файлов.txt'

# Вызываем функцию для сканирования и записи имен файлов
list_files_in_directory(directory_to_scan, output_file_path)
