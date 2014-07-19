-- prioritize Spotify first
--check if spotify is open
if application "Spotify" is running then
	--bring up dialog box, ask user to:
	--play/pause current song, play the next song, or play the last song
	tell application "Spotify"
		if player state is not playing then
			playpause
			set MessageNumber to 0
			set defaultCommand to "none"
		else
			set MessageNumber to 1
			set defaultCommand to ">>>"
		end if
	end tell

	if MessageNumber is equal to 0 then
		set question to display dialog "Give the current media player a command:" buttons {"<<<", ">>>"} with title "Media Player Script" giving up after 3
	else if MessageNumber is equal to 1 then
		set question to display dialog "Give the current media player a command:" buttons {"<<<", "play/pause", ">>>"} default button defaultCommand with title "Media Player Script" giving up after 3
	end if

	set answer to button returned of question
	if answer is equal to "" then
		set answer to defaultCommand
	end if

	--depending on user input tell spotify:
    --to playpaus, to next track, or to previous track
	tell application "Spotify"
		if answer is equal to "play/pause" then
			playpause
		else if answer is equal to ">>>" then
			next track
		else if answer is equal to "<<<" then
			if player position < 3 then
				previous track
			else
				previous track
				previous track
			end if
		end if
	end tell

--only play iTunes when nothing else is open
--then proceed in similar fasion to above spotify script
else if application "iTunes" is running then
	--bring up dialog box, ask user to:
	--play/pause current song, play the next song, or play the last song
	tell application "iTunes"
		if player state is not playing then
			playpause
			set MessageNumber to 0
			set defaultCommand to "none"
		else
			set MessageNumber to 1
			set defaultCommand to ">>>"
		end if
	end tell

	if MessageNumber is equal to 0 then
		set question to display dialog "Give the current media player a command:" buttons {"<<<", ">>>"} with title "Media Player Script" giving up after 3
	else if MessageNumber is equal to 1 then
		set question to display dialog "Give the current media player a command:" buttons {"<<<", "play/pause", ">>>"} default button defaultCommand with title "Media Player Script" giving up after 3
	end if

	set answer to button returned of question
	if answer is equal to "" then
		set answer to defaultCommand
	end if

	--depending on user input tell spotify:
    --to playpaus, to next track, or to previous track
	tell application "iTunes"
		if answer is equal to "play/pause" then
			playpause
		else if answer is equal to ">>>" then
			next track
		else if answer is equal to "<<<" then
			if player position < 3 then
				previous track
			else
				previous track
				previous track
			end if
		end if
	end tell

-- if no media app is open, start Spotify and play some tunes!
else
	tell application "Spotify"
		activate
		-- Make sure shuffle & repeat is on
		if shuffling is false then
			set shuffling to true
			if repeating is false then
				set repeating to true
			end if
		end if
	
		delay 1
		
		set sound volume to 0
		-- Open the playlist via a web browser. Customize this to your own playlist.
		play track "spotify:user:127398584:starred"
		next track
		set sound volume to 100
	end tell
end if