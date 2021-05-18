from pytube.cli import on_progress
from pytube import YouTube
import os
import pandas as pd
import shutil

# Custom functions..
def download_video(video_url, resolution, download_path):
    # Try downloading the video...
    #  # Code such a way that, if got an error with 'mkv' should go for mp4.
    try:
        youtube = YouTube(video_url, on_progress_callback=on_progress)
        download_with_res = youtube.streams.filter(progressive=True, file_extension='mp4')

        if download_with_res.get_by_resolution(resolution) is not None:		# Checking whether the download of that resoltion is possible or not witht he progresive stream..
            print ('[INFO] Downloading "{0}" with the {1} resolution...'.format(youtube.title, resolution))
            download_with_res.get_by_resolution(resolution).download(download_path)
        else:
            print ('[ERROR] Sorry..!! "{0}" is not avaliable with the {1} resolution in progressive stream.'.format(youtube.title, download_resolution))
            print ('[INFO]  So, downloading the lowest resolution available..')
            download_with_res.get_lowest_resolution().download(download_path)	# Change to get_highest_resolution()... to get the hihgest instead..
    except EOFError as err:
        print("ERROR: " + err)

    else:
        print("File downloaded successfully..!!")


# Main code starts from here...
resolutions = ["720p", "480p", "360p", "240p", "144p"]
download_choice = int(input("1. Single File download\n2. Bulk download\nChoice: "))
download_resolution = ""
while download_resolution not in resolutions:
    download_resolution = input ('Please choose the proper resolution "720p", "480p", "360p", "240p", "144p": ')
    #print ("Entered")


if download_choice == 1:
    video_url = input("Please paste the video URL here: ")
    download_video(video_url, download_resolution, ".")
else:
    csv_file_str = input("Please paste the path of the CSV file: ")
    destination_loc = input("Please paste the path of the destination: ")
    start_list_idx = int(input("From where the playlist continues(i.e., input a number): "))
    os.chdir(csv_file_str)
    if 'temp' not in os.listdir(destination_loc):
        print ("[INFO] 'temp' directory not found, creating temp directory in the '{}' path...".format(destination_loc))	
        os.mkdir("temp")	
    #print (os.listdir())
    #os.chdir(csv_file_str)
    csv_file = pd.read_csv('file.csv')
    for i in range(csv_file.shape[0]):
        download_video(csv_file['Link'][i], download_resolution, 'temp')
        print("File downloaded successfully..!!")
        try:
            #if destination_loc == '.':		# i.e., when it is the current directory..
            filename = os.listdir(destination_loc+r'/temp')[0]
            #print("File found is " + filename)
            os.rename(destination_loc+'/temp/'+filename, destination_loc+'/temp/'+str(i+start_list_idx)+'-'+filename)	# Adding the index-value to the user..
            print("File successfully renamed to " + str(i+1)+'-'+filename)
            shutil.move(destination_loc+'/temp/'+str(i+start_list_idx)+'-'+filename, destination_loc)
            print("File sucessfully moved to "+ destination_loc)
        except IOError as error:
            print("[**ERROR**] "+ error)
        else:
            print("All operations done on downloaded file..!!")

    # Removing the traces...
    if os.listdir(destination_loc+'/temp') is None:
        print ('[WARNING] "temp" directory not deleted after operation as some files are not downloaded completely..')
    else:
        print ("[INFO] Successfully removed all traces. i.e., Deleted 'temp' directory successfully..")
        os.rmdir("temp")

'''
Guide:	Downloading video files with status bar - Youtube
    pytube documentations


    Work done on 17-12-2020 ~ Thursday_3

    Suggested Updates:
    Saving all these operations done in a LOG file.

Update-log: on 18th April, 2021 ~ Sunday_3
    * Changes made: Added the option of downloading with the desired resoltion..
    * Made some info messages..
    * Updated the path format for linux..
    * Updated the feature of adding a file with desired start_playlist-index
'''
