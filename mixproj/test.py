import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import datetime

def send_email(subject, body, to_email):
    # Email configuration
    from_email = "hsh971072167@gmail.com"
    password = "ASDZXC//123"
    smtp_server = "smtp.gmail.com"
    smtp_port = 587

    # Create message container
    msg = MIMEMultipart()
    msg['From'] = from_email
    msg['To'] = to_email
    msg['Subject'] = subject

    # Attach body to email
    msg.attach(MIMEText(body, 'plain'))

    # Connect to SMTP server
    server = smtplib.SMTP(smtp_server, smtp_port)
    server.starttls()
    server.login(from_email, password)

    # Send email
    server.send_message(msg)
    server.quit()

if __name__ == "__main__":
    # Get today's date
    today_date = datetime.datetime.today().strftime('%Y-%m-%d')

    # Prepare email content
    subject = f"Daily Report - {today_date}"
    body = "This is your daily report. Please find attached the details."

    # Specify recipient email address
    to_email = "hsh971072167@gmail.com"

    # Send email
    send_email(subject, body, to_email)
