### Key Responsibilities
- Enable end-users to access the Internet via a number of applications ( email, web browsing, skype, whatsapp, youtube, social media..)
    - Writing data off to the network in a format that is compliant with the protocol in use.
    - Reading data from the end-user.
    - Providing useful applications to end users.
- Network Application Architectures
    - Client Server Architecture
    - Data Centers
    - Peer-to-peer ( P2P ) ex:- bittorrent
        - P2P architectures are self scaling.
    - Hybrid
- How processes communicates ?
    - Program vs Process vs Thread
        - **Program** :- Simply an executable.
        - **Process** :- currently running instance of a program. So one program can have several copies of it running at once.
        - **Thread** :- lightweight process. One process can have multiple running threads.
    - Sockets
        - Processes on different machines send messages to each other through the computer network.
        - The interface between a process and the computer network is called a socket.
        - Sockets are purely software interfaces.
        - Processes simply direct their messages to sockets and don’t worry about it after that.
        - Combination of **IP address + port**
    - Ports
        - Large number of applications running on an end system which has same IP address.
        - How to differentiate among them and connect to them ?
        - Port comes in when need to connect to particular application on an end system.
        - Two types of ports:- **ephemeral and reserved**.
- HTTP: The Basics
    - Objects
        - Web pages are objects that consist of other objects.
        - An object is simply a file like an HTML file, PNG file, MP3 file, etc.
        - Each object has a URL.
    - Anatomy of a URL :-
        - Universal Resource Locator used to locate files on the server. It consist of
            - **Protocol** in use
            - The **hostname** of server
            - **Location** of file
            - **Arguments** to the file
            - Consider an exmaple
                ```

                http://www.example.com/files/image1.png?user_id=10

                http               - protocol
                www.example.com    - hostname
                /files/image1.png  - location
                user_id            - arguments
                ```
    - HTTP
        - It's a client server protocol that specifies how web clients requests web pages from web servers and how servers respond to them.
        - There are other request-response protocol as well, HTTP is one of them.
        - HTTP is a stateless protocol. It means, if a client is sending same request again and again, server would not know that it is coming from the same client requesting the same object.
        - It depends on underlying transport layer protocols called UDP and TCP. HTTP uses TCP.
        - Types of HTTP Connections:
            - Non-persistent:- Uses one TCP connection per request ( connection type 1.0 )
            - Persistent:- Uses a single client-server TCP connection for all the HTTP request-response for a session. If there have been no request for a while server can close the connection. The duration of time before the server closes the connection is configurable. ( connection type 1.1 )
- HTTP Request Messages
    - Sample request message
        ```
        1. GET /path/to/file/index.html HTTP/1.1
        2. Host: www.example.com
        3. Connection: close
        4. User-agent: Mozilla/5.0
        5. Accept-language: fr
        6. Accept: text/html
        7.
        ```
    - Each line of message ends with two control characters: **carriage return and line feed**: \r\n
    - First line is request line and rest of the lines are header lines.
        ```
        GET /path/to/file/index.html HTTP/1.1

        method       - GET
        url          - /path/to/file/index.html
        http version - HTTP/1.1
        ```
    - Common Methods:- GET, POST, PUT, DELETE, HEAD
    - Difference between URL and URI
        - URLs are used to identify an object over web.
            ex:- protocol://hostname:port/path-and-file-name
        - URIs are more specific than URLs. They can locate fragments within objects too.
    - Read more about HTTP headers here.
        - https://en.wikipedia.org/wiki/List_of_HTTP_header_fields

- HTTP Response Message
    - Sample response message
        ```
        HTTP/1.1 200 OK
        Connection: close
        Date: Tue, 18 Aug 2015 15: 44 : 04 GMT
        Server: Apache/2.2.3 (CentOS)
        Last-Modified: Tue, 18 Aug 2015 15:11:03 GMT 
        Content-Length: 6821
        Content-Type: text/html

        [The object that was requested]
        ```
    - Three parts to it:
        - Status line:-  status lines start with the HTTP version
        - Status Code:- comes next, which tells the client if the request succeeded or failed.
            - 1xx :- Informational category
            - 2xx :- Success category
            - 3xx :- Redirection
            - 4xx :- Client error
            - 5xx :- Server error
        - Header Lines
            - Conneciton type, date, server, last modified, content length, content type
        - How HTTP headers are choosen i.e request headers by browser and response headers by server ?
            - That depends on a complex mix of factors such as the browser, the user configurations and products.

- Cookies
    - HTTP is a stateless protocol, but we often see websites where session state is needed.
    - Cookies are unique string identifiers that can be stored on the client’s browser.
    - These identifiers are set by the server through HTTP headers when the client first navigates to the website.
    - After the cookie is set, it’s sent along with subsequent HTTP requests to the same server. This allows the server to know who is contacting it and hence serve content accordingly.
    - Set-cookie header
        - When a server wants to set a cookie on the client-side, it includes the header Set-cookie: value in the HTTP response
        - This value is then **appended to a special cookie file stored on your browser**.
        - The cookie file contains:-
            - The website’s domain
            - The string value of the cookie
            - The date that the cookie expires (yes, much like actual cookies, they do expire)
    - Dangers of cookie
        - cookies have been severely abused in the past.
        - If a website has stored a cookie on your browser, it knows exactly when you visit it, what pages you visit and in what order.
        - Third party cookies
            -  Third-party cookies are cookies set for domains that are not being visited.
            -  They can track what you do on other websites.
            - Example:
                - A user visits amazon.com
                - A cookie for free-stats.com is subsequently set on their browser because free-stats has placed an advertisement on Amazon. Notice that this is a third-party cookie!
                - Suppose, the user visits ebay.com, and eBay also has placed an advertisement for free-stats.com.
                - The same cookie set on the Amazon site will be reused and sent to free-stats along in an HTTP request with the name of the host that the user is on.
                - Free-stats can in this way track every website the user visits that they are advertising on and create more targeted ads in order to generate greater revenue.
    - Most modern browsers come with the in-built option to block third-party cookies.
    - Blocking Third-Party Cookies Is Not Enough!
    - Workarounds:
        - Respawning cookies
        - Flash cookies
        - Entity tags
        - Canvas fingerprinting

- Email: SMTP
    - Email has been a key application of the Internet since its early days, almost all formal or official correspondences occur on email.
    - One popular choice is a combination of POP3 and SMTP.
    - One is used to send emails that are stored in a user’s inbox and the other is used to retrieve emails sent to you.
    - SMTP uses TCP, which means that transfers are reliable. The connection is established at port 25.
    - User Agents as agents that allow users to compose, view, delete, reply to, and forward emails. Applications such as Apple Mail, Microsoft Outlook, and Gmail’s webmail are examples of user agents.
    - All SMTP messages have to be encoded into 7-bit ASCII.
    - How SMTP works ?
        - When an email is sent, its sent to the sender’s SMTP server using the SMTP protocol.
            - The SMTP server is configured in your email client.
        - The email is now placed on a message queue in the sending SMTP server.
        - Then, the SMTP server initiates a connection with the recipient server and will conduct an initial SMTP handshake.
            - If the recipient is on the same SMTP server as the sender ( both are at gmail.com ), then the SMTP server doesn’t need to connect to the recipient’s server.
        - The SMTP server will finally send the message to the recipient’s email server.
        - The email is then downloaded from the recipient’s SMTP server using other protocols when the recipient logs in to their email account or 'user agent.’
    - **NOTE**:- SMTP is a push protocol because the email client sends the email out to the server when it needs to. Which means it only sends data to servers. Other protocols called Mail Access Protocols such as POP and IMAP are used for getting email from a server and are called pull protocols because the client asks their POP/IMAP server if they have any new messages whenever they feel like.
    - nslookup, or name server lookup, is a command-line tool that can be used to find the name and IP address of the SMTP server for a domain like live.com or gmail.com.
        ```
        nslookup -type=mx https://outlook.live.com
        nslookup -type=mx gmail.com
        nslookup -type=mx mail.yahoo.com
        ```
    - The **mx in the -type=mx** flag stands for Mail Exchanger record, which essentially means the SMTP server.

- Email: POP & IMAP
    - POP and IMAP are used to retrieve email from an email server.
    - POP
        - The most commonly used version of the Post Office Protocol (POP) is version 3, or POP3.
        - POP phases
            - Emails are simply downloaded from the server in 4 phases: connect, authorize, transaction, update.
            - Connect:- The user agent first connects to the POP3 server on TCP using port 110.
            - Authorize:- The user agent authenticates the user with a username and a password.
            - Transaction:- The user can now retrieve emails and mark emails for deletion.
            - Update:- After the user agent quits and closes the POP3 session, the server makes updates based on the user’s commands.
        - Other folders such as sent items, outbox, or drafts are not synced. So **POP3 does not synchronize the folders**.
        - POP Modes
            - **Download and delete**:- Once emails are downloaded from the server to the user agent, they are all deleted from there.
            - **Download and keep**:- Emails are not deleted from the server once they are downloaded onto the user agent.
    - IMAP ( Internet Message Access Protocol )
        - Also a mail access protocol used for retrieving email.
        - It is a bit more complex than POP and hence allows you to view your email from multiple devices.
        - With IMAP
            - Emails are kept on the server and not deleted.
            - Local copies of the emails are cached on each device.
            - It syncs up all of the user’s folders including custom folders.
            - The inbox would look exactly the same on all clients.
            - If an email is deleted from one user agent, it will be deleted off the server.
            - Deleted emails won’t be visible from other devices either.

- DNS
    - How do we find the things on internet ?
        - Addresses or Locations:- addresses are typically IP addresses, and routers know the map.
        - Names:- domain names, or the unique name that identifies a websites, are mapped into IP addresses based on lookup service that uses a database.
        - Content based addressing:- The content itself is used to look up its location.
    - DNS, the client-server application layer protocol that translates hostnames on the Internet to IP addresses.
    - DNS is not just a protocol. It also consists of a distributed database of names that map to IP addresses. So essentially it’s a directory service.
    - DNS servers exists in hierarchy.
        ```
        sub-domain.exmaple.com

        com -> top level domain
        example -> Second level domain
        subdomain -> sub-domain
        ```
    - DNS servers
        - Root DNS server
            - Root DNS servers are the first point of contact for a DNS query (after the client’s local cache of names and IP addresses).
            - They exist at the top of the hierarchy and point to the appropriate TLD server in reply to the query.
            - So a query for www.example.com would return the IP address of a server for the top-level domain, com.
        - Top Level server
            - Servers in the top-level domain hold mappings to DNS servers for certain domains.
            - Each domain is meant to be used by specific organizations only.
            - com ( commercial purpose only ), edu ( educational institutes ), gov ( only by US govt ), mil ( military org ), net, org etc.
            - Maintained by ICANN
        - Authoritative servers
            - Every organization with a public website or email server provides DNS records. These records have hostname to IP address mappings stored for that organization.
            - These records can either be stored on a dedicated DNS server for that organization or they can pay for a service provider to store the records on their server.
            - This is the next link in the chain. If this server has the answer that we are looking for, the IP address that it has is finally returned to the client.
            - However, this server may not have the sought after answer if the domain has a sub-domain. In that case, this server may point to a server that has records of the subdomain.
            - For instance, if the DNS record for cs.stanford.edu is being looked for, a DNS server separate from ‘stanford.edu’ may hold records for the sub-domain 'cs.'
        - Local DNS Cache
            - DNS mappings are often also cached locally on the client end-system to avoid repetitive lookups and saves time for often visited websites.
            - This is done via an entity called the local resolver library, which is part of the OS. The application makes an API call to this library.
            - If the local resolver library does not have a cached answer for the client, it will contact the organization’s local DNS server.
            - This local DNS server is typically configured on the client machine either using a protocol called **DHCP or can be configured statically**.
        - Local DNS Servers
            - Local DNS servers are usually the first point of contact after a client checks its local cache.
            - These servers are generally **hosted at the ISP** and contain some mappings based on what websites users visit.

    - Finding Authoritative name servers
        ```
        host -t ns google.com
        ```
        - Host is a DNS lookup utility.
        - It is normally used to map hostnames to IP addresses.
        - -t :- type flag
        - ns specifies the type. It stands for the name server in this case.
        ```
        cat /etc/resolv.conf

        To check IP address of your local DNS server
        ```
    - DNS: Records and messages
        - The DNS distributed database consists of entities called RRs, or Resource Records.
        - RRs contain some or all of the following values:
            - Name of the domain
            - Resource data (RDATA) provides information appropriate for the type of resource record.
            - Type of the resource record.
            - Time-to-live (TTL) is how long the record should be cached by the client in seconds.
            - DNS Class. There are many types of classes but we’re mainly concerned with IN which implies the ‘Internet’ class.
        - Type of resource records
            - **Address type** or **A** addresses contain IPv4 address to hostname mappings.
            - **Canonical name** or **CNAME** records are records of alias hostnames against actual hostnames.
            - **Mail Exchanger** or **MX records** are records of the server that accepts email on behalf of a certain domain.
        - DNS Messages
            - There are a few kinds of DNS messages, out of which the most common are query and reply, and both have the same format.
    - nslookup
        - can be used to look at DNS records.
        ```
        nslookup -type=A google.com

        Server:         2409:4053:287:34a2::28
        Address:        2409:4053:287:34a2::28#53

        Non-authoritative answer:
        Name:   google.com
        Address: 142.250.194.110
        ```
        - The first two lines are the IP address of the local DNS server.
        - The last few lines return the type A RR that maps google.com to the IP address 142.250.194.110
        - It says ‘non-authoritative’ because the answer is coming from a local DNS server’s cache, and not from Educative’s authoritative DNS server.
        - If you’re wondering what TTL values look like, run with **-debug** flag
    - dig
        - command-line tool used to query DNS servers.
        - dig stands for **domain information groper**, and it displays the actual messages that were received from DNS servers.

- BitTorrent
    - BitTorrent is a key protocol and has millions of users simultaneously and actively sharing and downloading hundreds of thousands of files of all types: music, movies, books, and so on.
    - BitTorrent falls more in the hybrid category than pure P2P.
    - Protocol for P2P file sharing.
    - How it works ?
        - Trackers and torrent files
            - How do clients find peers to connect to ?
                - Well, clients connect to a **special tracker node** first. The tracker responds with the IP and the port of a few other peers who are downloading the same file.
                - Modern BitTorrent clients are trackerless and use a Distributed Hash Table instead
            - But how do clients find the **tracker** in the first place ?
                - Clients begin by downloading a ‘torrent file’ from a web server which has the URL of the tracker.
                - The torrent file also contains a SHA1 hash of each file chunk.
