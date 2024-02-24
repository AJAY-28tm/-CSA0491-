import requests
from bs4 import BeautifulSoup
import tkinter as tk
from tkinter import messagebox, simpledialog
import turtle
import os

def draw_spider_logo(turtle_obj):
    turtle_obj.penup()
    turtle_obj.goto(0, 0)
    turtle_obj.pendown()
    turtle_obj.color("red")
    turtle_obj.speed(9)

    # Paste your Spider-Man spider logo drawing code here
    turtle_obj.begin_fill()
    turtle_obj.circle(20)
    turtle_obj.end_fill()

    turtle_obj.penup()
    turtle_obj.setheading(270)
    turtle_obj.left(60)
    turtle_obj.pendown()
    turtle_obj.begin_fill()
    turtle_obj.forward(20)
    turtle_obj.right(80)
    turtle_obj.forward(70)
    turtle_obj.right(147)
    turtle_obj.forward(70)
    turtle_obj.right(80)
    turtle_obj.forward(20)
    turtle_obj.penup()
    turtle_obj.end_fill()

    turtle_obj.pendown()
    turtle_obj.goto(10,35)
    turtle_obj.pendown()
    turtle_obj.begin_fill()
    turtle_obj.left(20)
    turtle_obj.forward(25)
    turtle_obj.right(60)
    turtle_obj.forward(50)
    turtle_obj.left(120)
    turtle_obj.forward(80)
    turtle_obj.right(175)
    turtle_obj.forward(95)
    turtle_obj.right(127)
    turtle_obj.forward(63)
    turtle_obj.left(60)
    turtle_obj.forward(18)
    turtle_obj.end_fill()

    turtle_obj.pendown()
    turtle_obj.goto(13,25)
    turtle_obj.pendown()
    turtle_obj.begin_fill()
    turtle_obj.left(90)
    turtle_obj.left(90)
    turtle_obj.forward(20)
    turtle_obj.right(60)
    turtle_obj.forward(80)
    turtle_obj.left(125)
    turtle_obj.forward(130)
    turtle_obj.right(175)
    turtle_obj.forward(145)
    turtle_obj.right(128)
    turtle_obj.forward(95)
    turtle_obj.left(60)
    turtle_obj.forward(20)
    turtle_obj.end_fill()

    turtle_obj.pendown()
    turtle_obj.goto(-10,35)
    turtle_obj.pendown()
    turtle_obj.begin_fill()
    turtle_obj.right(80)
    turtle_obj.forward(25)
    turtle_obj.left(60)
    turtle_obj.forward(50)
    turtle_obj.right(120)
    turtle_obj.forward(80)
    turtle_obj.left(175)
    turtle_obj.forward(95)
    turtle_obj.left(127)
    turtle_obj.forward(63)
    turtle_obj.right(60)
    turtle_obj.forward(18)
    turtle_obj.end_fill()

    turtle_obj.pendown()
    turtle_obj.goto(-13,25)
    turtle_obj.pendown()
    turtle_obj.begin_fill()
    turtle_obj.right(90)
    turtle_obj.right(90)
    turtle_obj.forward(20)
    turtle_obj.left(60)
    turtle_obj.forward(80)
    turtle_obj.right(125)
    turtle_obj.forward(130)
    turtle_obj.left(175)
    turtle_obj.forward(145)
    turtle_obj.left(128)
    turtle_obj.forward(95)
    turtle_obj.right(60)
    turtle_obj.forward(20)
    turtle_obj.end_fill()

    turtle_obj.pendown()
    turtle_obj.goto(15,12)
    turtle_obj.left(60)
    turtle_obj.begin_fill()
    turtle_obj.forward(20)
    turtle_obj.right(40)
    turtle_obj.forward(95)
    turtle_obj.right(100)
    turtle_obj.forward(135)
    turtle_obj.right(175)
    turtle_obj.forward(120)
    turtle_obj.left(90)
    turtle_obj.forward(80)
    turtle_obj.left(40)
    turtle_obj.forward(20)
    turtle_obj.end_fill()

    turtle_obj.pendown()
    turtle_obj.goto(11,8)
    turtle_obj.left(150)
    turtle_obj.begin_fill()
    turtle_obj.forward(25)
    turtle_obj.right(10)
    turtle_obj.forward(65)
    turtle_obj.right(95)
    turtle_obj.forward(70)
    turtle_obj.right(175)
    turtle_obj.forward(60)
    turtle_obj.left(85)
    turtle_obj.forward(65)
    turtle_obj.left(15)
    turtle_obj.forward(15)
    turtle_obj.end_fill()

    turtle_obj.pendown()
    turtle_obj.goto(-15,14)
    turtle_obj.right(3)
    turtle_obj.begin_fill()
    turtle_obj.forward(20)
    turtle_obj.left(40)
    turtle_obj.forward(95)
    turtle_obj.left(100)
    turtle_obj.forward(135)
    turtle_obj.left(175)
    turtle_obj.forward(120)
    turtle_obj.right(90)
    turtle_obj.forward(80)
    turtle_obj.right(40)
    turtle_obj.forward(20)
    turtle_obj.end_fill()
    turtle_obj.penup()

    turtle_obj.pendown()
    turtle_obj.goto(-11,8)
    turtle_obj.right(90)
    turtle_obj.right(60)
    turtle_obj.begin_fill()
    turtle_obj.forward(25)
    turtle_obj.left(10)
    turtle_obj.forward(65)
    turtle_obj.left(95)
    turtle_obj.forward(70)
    turtle_obj.left(175)
    turtle_obj.forward(60)
    turtle_obj.right(85)
    turtle_obj.forward(65)
    turtle_obj.right(15)
    turtle_obj.forward(15)
    turtle_obj.end_fill()

    turtle_obj.speed(2)

def get_links(url):
    try:
        response = requests.get(url)
        soup = BeautifulSoup(response.text, 'html.parser')
        links = [a['href'] for a in soup.find_all('a', href=True)]
        return links
    except Exception as e:
        print(f"Error while getting links from {url}: {e}")
        return []

def save_links_to_file(links, file_path):
    with open(file_path, 'w') as file:
        for link in links:
            file.write(link + '\n')

def web_crawler(start_url, max_urls, text_widget, output_file):
    visited_urls = set()
    crawled_links = []  # List to store all crawled links
    to_crawl = [(start_url, 1)]  # Tuple with URL and its number
    crawled_urls = 0

    while to_crawl and crawled_urls < max_urls:
        current_url, link_number = to_crawl.pop(0)

        if current_url.lower() == 'stop':
            text_widget.insert(tk.END, "Crawling stopped.\n")
            break

        if current_url not in visited_urls:
            text_widget.insert(tk.END, f"{link_number}. Crawling {current_url}\n")
            visited_urls.add(current_url)
            crawled_urls += 1

            links = get_links(current_url)
            for i, link in enumerate(links, start=link_number + 1):
                to_crawl.append((link, i))
                crawled_links.append(link)  # Append link to the list

    # Save all crawled links to a file
    with open(output_file, 'w') as file: 
        for link in crawled_links:
            file.write(link + '\n')

    text_widget.insert(tk.END, f"Crawling completed. Crawled {crawled_urls} URLs.\n")
    text_widget.insert(tk.END, f"All crawled links saved to: {output_file}\n")

def start_crawling():
    start_url = url_entry.get()
    max_urls = int(max_urls_entry.get())
    output_file = "crawled_links.txt"  # File to store all crawled links

    if not start_url:
        messagebox.showerror("Error", "Please enter a starting URL.")
        return

    try:
        result_text.delete(1.0, tk.END)  # Clear previous results
        result_text.insert(tk.END, "Initial Crawling:\n")
        web_crawler(start_url, max_urls, result_text, output_file)
        crawl_specific_link(result_text, max_urls)
    except Exception as e:
        messagebox.showerror("Error", f"An error occurred: {e}")    

def crawl_specific_link(text_widget, max_urls):
    try:
        choice = int(simpledialog.askstring("Crawl Specific Link", "Enter the number of the link you want to crawl (or enter 0 to skip): "))
        if 1 <= choice <= max_urls:
            link_to_crawl = text_widget.get(f"{choice}.0", f"{choice}.end").strip()
            max_urls_to_crawl = int(simpledialog.askstring("Crawl Specific Link", f"How many URLs to crawl from {link_to_crawl}? "))
            newly_crawled_text = f"\n\nNewly Crawled from {link_to_crawl}:\n"
            text_widget.insert(tk.END, newly_crawled_text)
            web_crawler(link_to_crawl, max_urls_to_crawl, text_widget)
    except ValueError:
        pass  # User entered an invalid choice or chose to skip




# Create loading window
loading_window = tk.Tk()
loading_window.title("Loading...")
loading_canvas = tk.Canvas(loading_window, width=400, height=400)
loading_canvas.pack()

# Turtle graphics for loading animation
loading_turtle = turtle.RawTurtle(loading_canvas)
loading_turtle.speed(2)

loading_label = tk.Label(loading_window, text="Loading...", font=("Helvetica", 16))
loading_label.pack()

# Draw the Spider-Man spider logo
draw_spider_logo(loading_turtle)

loading_window.after(2000, loading_window.destroy)  # Close loading window after 2 seconds

# Run the loading Tkinter event loop
loading_window.mainloop()

# Create the main window
window = tk.Tk()
window.title("Web Crawler")

# Create and place widgets
tk.Label(window, text="Enter starting URL:").pack()
url_entry = tk.Entry(window, width=50)
url_entry.pack()

tk.Label(window, text="Enter max URLs to crawl:").pack()
max_urls_entry = tk.Entry(window)
max_urls_entry.pack()

start_button = tk.Button(window, text="Start Crawling", command=start_crawling)
start_button.pack()

result_text = tk.Text(window, height=15, width=80)
result_text.pack()

# Run the Tkinter event loop for the main window
window.mainloop()
