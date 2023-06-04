from selenium import webdriver

browser = webdriver.Chrome()
browser.get('https://web.whatsapp.com/')

sign_in = browser.find_element_by_link_text('Sign in')
sign_in.click()

username_box = browser.find_element_by_id('login_field')
username_box.send_keys('akshaygade2327@gmail.com')

password_box = browser.find_element_by_id('password')
password_box.send_keys('BiryaniBhat23')
password_box.submit()

browser.q