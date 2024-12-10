import telebot
import os
import subprocess
import uuid

from moviepy.editor import AudioFileClip

# Bot token from Telegram
TOKEN = ''
bot = telebot.TeleBot(TOKEN)

# Dictionary to store photos for each user by chat ID
user_photos = {}

@bot.message_handler(commands=['start'])
def start(message):
    """
    Handles the /start command. Sends a welcome message and instructions to the user.
    """
    chat_id = message.chat.id
    user_photos[chat_id] = []  # Initialize photo storage for this user
    welcome_message = """
Hi! I can create video slideshows from your photos and music. Just send me your photos and an audio file.
I support the following commands:
/start - Start working with me and view this message again
/create_video - Create a video slideshow from the uploaded photos and audio
    """
    bot.send_message(chat_id, welcome_message)

@bot.message_handler(content_types=['photo'])
def handle_photo(message):
    """
    Handles photo uploads. Downloads the photo to the server and stores it for the user.
    """
    chat_id = message.chat.id
    file_id = message.photo[-1].file_id  # Get the file ID of the highest quality photo
    file_info = bot.get_file(file_id)
    file_path = file_info.file_path
    photo_url = f'https://api.telegram.org/file/bot{TOKEN}/{file_path}'
    photo_file = f'photo_{uuid.uuid4()}.jpg'  # Generate a unique name for the photo
    user_photos[chat_id].append(photo_file)

    subprocess.run(['wget', '-O', photo_file, photo_url])  # Download the photo using wget
    bot.send_message(chat_id, 'Photo successfully uploaded!')

@bot.message_handler(content_types=['audio'])
def handle_audio(message):
    """
    Handles audio uploads. Downloads the audio file to the server.
    """
    chat_id = message.chat.id
    file_id = message.audio.file_id  # Get the file ID for the audio
    file_info = bot.get_file(file_id)
    file_path = file_info.file_path
    audio_url = f'https://api.telegram.org/file/bot{TOKEN}/{file_path}'
    audio_file = 'audio.mp3'  # Save audio with a fixed name

    subprocess.run(['wget', '-O', audio_file, audio_url])  # Download the audio using wget
    bot.send_message(chat_id, 'Audio successfully uploaded!')

def cleanup_files(chat_id):
    """
    Cleans up all temporary files related to the user's session.
    """
    photos = user_photos.get(chat_id)
    if photos:
        for photo in photos:
            if os.path.exists(photo):
                os.remove(photo)  # Remove photo files
        photos.clear()
    if os.path.exists('audio.mp3'):
        os.remove('audio.mp3')  # Remove the audio file
    if os.path.exists('output.mp4'):
        os.remove('output.mp4')  # Remove the output video

@bot.message_handler(commands=['create_video'])
def create_video(message):
    """
    Handles the /create_video command. Generates a video slideshow from the user's photos and audio.
    """
    chat_id = message.chat.id
    photos = user_photos.get(chat_id)
    if not photos:
        bot.send_message(chat_id, 'Error! No photos found.')
        return
    if not os.path.exists('audio.mp3'):
        bot.send_message(chat_id, 'Error! No audio found.')
        return

    try:
        # Sort and rename photos to sequential filenames for ffmpeg
        photos.sort()
        for i, photo in enumerate(photos):
            new_filename = f'image{i}.jpg'
            if os.path.exists(new_filename):
                os.remove(new_filename)  # Remove existing file if it exists
            os.replace(photo, new_filename)

        # Get the duration of the audio file
        audio_clip = AudioFileClip('audio.mp3')
        audio_duration = audio_clip.duration

        # Calculate frame duration based on the number of photos and audio duration
        frame_duration = audio_duration / len(photos)
        
        # Create video using ffmpeg
        ffmpeg_command = (
            f'ffmpeg -y -r {1 / frame_duration} -i image%d.jpg -i audio.mp3 '
            f'-vf "scale=-2:720" -c:v libx264 -c:a aac -b:a 192k -pix_fmt yuv420p output.mp4'
        )
        subprocess.run(ffmpeg_command, shell=True, check=True)
        
        bot.send_message(chat_id, 'Video successfully created!')
        # Send the video to the user
        with open('output.mp4', 'rb') as video:
            bot.send_video(chat_id, video)
    except subprocess.CalledProcessError:
        bot.send_message(chat_id, 'Failed to create the video.')
    finally:
        cleanup_files(chat_id)

if __name__ == '__main__':
    # Start the bot in polling mode
    bot.polling(none_stop=True)
