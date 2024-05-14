# bank-of-nate
A simple and poorly designed terminal application for bank management. Create, view, and add bank records.

NOTE: This is more intended to demonstrate simple I/O and file handling. A proper application would use hashes, databases, and not have hard-coded credentials.

This application can:
-Create Records
-View Records
-Modify Records
-(New) Close an Account

Application also checks input for name collisions, so no two records can have the same file name. Credentials are also 
required to create or modify an account. 

Application also annotates each record entry with the time and user.

--Initial Login for Original Code--
UN: admin
PW: 113113
-Password for admin functions: 0000

I advise you compile this application into it's own directory, since it generates text files every time you create a record.

UPDATE: App can now close accounts.
