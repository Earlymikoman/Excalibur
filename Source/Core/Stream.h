//------------------------------------------------------------------------------
//
// File Name:	Stream.h
// Author(s):	Doug Schilling (dschilling)
// Project:		Project 4
// Course:		CS230S25
//
// Copyright � 2025 DigiPen (USA) Corporation.
//
// Helpful Links:
//   https://learn.microsoft.com/en-us/dotnet/standard/io/file-path-formats
//
//------------------------------------------------------------------------------

#pragma once

#include <stdio.h>

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

typedef FILE* Stream;
typedef struct DGL_Vec2 Vector2D;
typedef struct DGL_Color DGL_Color;

//------------------------------------------------------------------------------
// Public Constants:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Open a file for reading.
// (NOTE: Use fopen_s() with the "rt" option.)
// (NOTE: You must generate the following trace message if the file was not opened successfully:
//	  TraceMessage("Error: StreamOpen could not open file %s; %s", filePath, errorMsg);
//	  Where errorMsg is a char array containing the error message obtained using strerror_s().)
// Params:
//	 filePath = The file to be opened for reading.
// Returns:
//	 0 if filePath is 0 or the file could not be opened.
//	 Pointer to a FILE object if the file was opened successfully.
Stream StreamOpen(const char* filePath);

// Read a single integer from a stream.
// (NOTE: Verify that the stream is valid first.)
// (NOTE: Use fscanf_s() to scan the input stream for an integer.)
// Params:
//	 stream = The file stream from which to read.
// Returns:
//	 0 if the stream was not opened succesfully;
//	 otherwise, an integer value read from the file.
int StreamReadInt(Stream stream);

// Read a single float from a stream.
// (NOTE: Verify that the stream is valid first.)
// (NOTE: Use fscanf_s() to scan the input stream for a float.)
// Params:
//	 stream = The file stream from which to read.
// Returns:
//	 If the stream was opened succesfully,
//	   then return a float value read from the file,
//	   else return 0.
float StreamReadFloat(Stream stream);

// Read a token (a single word) from a file.
// Suggested steps:
//	 - Set the first value in tokenBuffer to 0
//	 - If the stream was opened successfully,
//	   - Read a std::string ("%s") into tokenBuffer using fscanf_s()
//	 - Return tokenBuffer
// Params:
//	 stream = The file stream from which to read.
// Returns:
//	 Pointer to tokenBuffer
const char* StreamReadToken(Stream stream);

// Close an opened stream.
// (NOTE: Do not attempt to close the stream if the pointer is null.)
// (PRO TIP: Avoid dangling pointers by setting the FILE pointer to 0.)
// Params:
//	 stream = The file stream to be closed.
void StreamClose(Stream * stream);

//------------------------------------------------------------------------------
