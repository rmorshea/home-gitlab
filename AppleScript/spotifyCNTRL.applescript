# prioritize Spotify first
if application "Spotify" is running then
	tell application "Spotify" to next track

# only play iTunes when nothing else is open
else if application "iTunes" is running then
    tell application "iTunes" to next track

# if no media app is open, start Spotify and play some tunes!
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