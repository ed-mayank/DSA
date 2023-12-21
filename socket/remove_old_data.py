import os
import datetime
import time

def get_line_timestamp(line):
    # This function should extract the timestamp from your data.
    # Modify it based on your actual data format.
    # Here, it assumes the timestamp is at the beginning of each line.
    timestamp_str = line.split()[0]
    timestamp = float(timestamp_str)
    return timestamp


def remove_old_data(file_path, threshold_seconds=10):
    current_time = time.time()
    threshold_time = current_time - threshold_seconds
    print(threshold_time)

    with open(file_path, 'r') as file:
        lines = file.readlines()

    # Filter lines that are newer than the threshold time
    print([get_line_timestamp(line) for line in lines])
    new_lines = [line for line in lines if get_line_timestamp(line) >= threshold_time]

    # Write the filtered lines back to the file
    print(new_lines)
    with open(file_path, 'w') as file:
        file.writelines(new_lines)


# Example usage
path = 'in.txt'
while True:
    remove_old_data(path)
    if os.path.getsize(path) == 0:
        break
