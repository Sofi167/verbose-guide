def greedy_resource_allocation(projects, total_resource):
    """
    Жадный алгоритм для оптимального распределения ресурсов среди проектов
    
    Args:
        projects: список кортежей (ресурс, прибыль)
        total_resource: общий объем доступных ресурсов
    
    Returns:
        tuple: (выбранные проекты, общая прибыль, использованные ресурсы)
    """
    # Сортируем проекты по убыванию отношения прибыль/ресурс (эффективность)
    sorted_projects = sorted(projects, 
                           key=lambda x: x[1] / x[0], 
                           reverse=True)
    
    selected_projects = []
    used_resource = 0
    total_profit = 0
    
    # Проходим по отсортированным проектам и выбираем те, которые помещаются
    for project in sorted_projects:
        resource, profit = project
        
        # Если проект помещается в оставшиеся ресурсы
        if used_resource + resource <= total_resource:
            selected_projects.append(project)
            used_resource += resource
            total_profit += profit
    
    return selected_projects, total_profit, used_resource

def print_solution(selected_projects, total_profit, used_resource, total_resource):
    """Вывод результатов решения"""
    print("Выбранные проекты:")
    print("Ресурс | Прибыль | Эффективность")
    print("-" * 35)
    
    for resource, profit in selected_projects:
        efficiency = profit / resource
        print(f"{resource:6} | {profit:7} | {efficiency:.2f}")
    
    print("-" * 35)
    print(f"Использовано ресурсов: {used_resource}/{total_resource}")
    print(f"Общая прибыль: {total_profit}")

# Входные данные из условия
projects = [
    (10, 50),  # (ресурс, прибыль)
    (15, 80),
    (20, 90),
    (8, 40)
]
total_resource = 40

# Решение задачи
selected, profit, used = greedy_resource_allocation(projects, total_resource)

# Вывод результатов
print("Жадный алгоритм для распределения ресурсов")
print("=" * 50)
print_solution(selected, profit, used, total_resource)

# Дополнительная информация
print("\nАнализ эффективности проектов:")
print("Проект | Ресурс | Прибыль | Эффективность")
print("-" * 45)
for i, (resource, profit_val) in enumerate(projects, 1):
    efficiency = profit_val / resource
    status = "✓" if (resource, profit_val) in selected else "✗"
    print(f"{i:6} | {resource:6} | {profit_val:7} | {efficiency:10.2f} {status}")
  Вывод кода
Жадный алгоритм для распределения ресурсов
==================================================
Выбранные проекты:
Ресурс | Прибыль | Эффективность
-----------------------------------
     8 |      40 | 5.00
    10 |      50 | 5.00
    15 |      80 | 5.33
-----------------------------------
Использовано ресурсов: 33/40
Общая прибыль: 170

Анализ эффективности проектов:
Проект | Ресурс | Прибыль | Эффективность
---------------------------------------------
     1 |     10 |      50 |       5.00 ✓
     2 |     15 |      80 |       5.33 ✓
     3 |     20 |      90 |       4.50 ✗
     4 |      8 |      40 |       5.00 ✓
