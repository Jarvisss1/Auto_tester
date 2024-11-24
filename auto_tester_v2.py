import subprocess
import os

def run_test(file_path, input_data, expected_output):
    exe_file = file_path.replace(".c", ".exe")  # Change to ".out" for macOS/Linux
    compile_process = subprocess.run(["gcc", file_path, "-o", exe_file], capture_output=True, text=True)
    
    if compile_process.returncode != 0:
        return "Compilation Error", compile_process.stderr.strip()
    
    # Run the executable and capture output
    run_process = subprocess.run([f"./{exe_file}"], input=input_data, capture_output=True, text=True)
    
    if run_process.returncode != 0:
        return "Runtime Error", run_process.stderr.strip()
    
    # Compare actual output with expected output
    actual_output = run_process.stdout.strip()
    status = "Passed" if actual_output == expected_output.strip() else "Failed"
    return status, actual_output

# Folder containing student submissions and test cases
submission_folder = "submissions/"
test_cases_folder = "test_cases/"

# List of questions and their test cases
questions = {
    "Q1_sort": ("Q1_input.txt", "Q1_output.txt"),
    "Q2_peak": ("Q2_input.txt", "Q2_output.txt"),
    "Q3_reverse_string": ("Q3_input.txt", "Q3_output.txt")
}

# Process each student submission
results = {}
for file in os.listdir(submission_folder):
    if file.endswith(".c"):
        file_path = os.path.join(submission_folder, file)
        roll_number = os.path.splitext(file)[0]  # Extract roll number from filename
        student_results = {}
        
        print(f"\nResults for Student: {roll_number}")
        for question, (input_file, output_file) in questions.items():
            with open(os.path.join(test_cases_folder, input_file)) as inp, open(os.path.join(test_cases_folder, output_file)) as out:
                input_data = inp.read()
                expected_output = out.read()
                status, actual_output = run_test(file_path, input_data, expected_output)
                
                # Print each question's status and output
                print(f"{question}: {status}")
                print(f"  Student Output: {actual_output}")
                print(f"  Expected Output: {expected_output.strip()}\n")
                
                student_results[question] = status
        
        results[roll_number] = student_results

# Print and log the overall results
with open("test_results.txt", "w") as log_file:
    for roll, test_result in results.items():
        log_line = f"{roll}: {test_result}"
        log_file.write(log_line + "\n")
