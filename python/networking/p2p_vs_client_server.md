### Quantitative comparison of p2p and client server arch.

- Let’s calculate how long it will take to transmit a file from one server to a number of clients based on both the P2P and server-client architectures. 
    - A server that can upload at a rate of up<sub>s</sub> ( bits/second )
    - There are N clients all wanting to download the same file from the server. Client i can upload at a rate of up<sub>i</sub> bits/sec and download at a rate of dwn<sub>i</sub> bits/sec.
    - The size of the file that all the peers want is S.

- Client server
    - Since N clients wants to download the same file of size S, server will have to upload NS bits. The upload rate of server is up<sub>s</sub>, so the server will take NS/up<sub>s</sub> to transmit file to all N clients.
    - The client with min download rate ( dwn<sub>min</sub> = min(dwn<sub>i</sub>) ) will take atleast S/dwn<sub>min</sub> time to download the full file.
    - So total time taken to transmit the file will be :- **max**{ NS/up<sub>s</sub>, S/dwn<sub>min</sub> }

- P2P
    - Initially, only the server has the file. It has to throw the file out into the network and to do that, it will take at least S/up<sub>s</sub> time.
    - While the file is being sent out into the network of peers, they start to distribute it amongst themselves.
    - The peer with the lowest download rate ( dwn<sub>min</sub> ) will take atleast S/dwn<sub>min</sub> to download the full file.
    - The file cannot be transmitted faster than the total upload speed of the entire network:
        - up<sub>sum</sub> = {up<sub>1</sub> + up<sub>2</sub> + ... + up<sub>n</sub>}
        - Since the file has to be distributed to all N peers, NS bits have to be transmitted, that will take NS/up<sub>sum</sub>
    - Therefore, the time taken in total to distribute :- **max**{ S/up<sub>s</sub>, S/dwn<sub>min</sub>, NS/up<sub>sum</sub> }

**Note**:- As the number of clients/peers N grows,  the time taken by the client-server architecture also grows. P2P networks are more scalable.
