- OSI model is layered architecture model. But why layers ?
    - Layered arch. gives us modularity by allowing us to discuss **specific, well defined parts of larger systems**.
    - This makes changing underlying implementation and bug identifying easier.
    - Layers are vertical:- Each layer provides some service to the layer above it. The layer above is not concerned with the details of how the layer below performs its services ( called abstraction )
    - Layers are horizontal:- Each layer at the sending end has a parallel in the receiving end.
    - Layers evolve independently
    - Encapsulation/Decapsulation:- Each layer adds its own header to the message coming from above and receiving entity on the other end removes it. Adding is called encapsulation and removing it is called decapsulation.

- Two most common models are:
    - OSI -> open system interconnection ( 7 layers )
    - TCP/IP -> Transmission Control Protocol/Internet Protocol ( 5 layers )
        - In TCP/IP all top 3 layers ( application, presentation and session ) are combined into a single layer ( application layer )


    | Layers| Mnemonic |
    | :---------------- | :--------: |
    | Application | Away |
    | Presentation | Pizza |
    | Session    | Sausage |
    | Transport | Throw |
    | Network | Not |
    | Data Link | Do |
    | Physical | Please |


### Application Layer
- These applications or protocols are almost always implemented in software.
- End-users interact with the application layer.
- The application layer is where most end-user applications such as web browsing and email live.
- The application layer is where an outgoing message starts its journey so it provides data for the layer below.

### Presentation Layer
- Presents data in a way that can be easily understood and displayed by the application layer.
    - Encoding is an example of such presentation.
- Encryption (changing the data so that it is only readable by the parties it was intended for) is also usually done at this layer.
- Abstracts: the presentation layer assumes that a user session is being maintained by the lower layers and transforms content presentation to suit the application.
- End-to-end Compression: The presentation layer might also implement end to end compression to reduce the traffic in the network.

### Session Layer
- The session layer’s responsibility is to take the services of the transport layer and build a service on top of it that manages user sessions.
    - The session layer must manage the mapping of messages delivered by the transport layer to the sessions.
- A session is an exchange of information between two or more communication devices or ends – be they computers, automated systems, or live active users.
- Abstracts: the session layer assumes that connections establishment and packet transportation is handled by the layers below it.

### Transport Layer
- The transport layer also has protocols implemented largely in software.
- Since the application, presentation and session layers may be handing off large chunks of data, the transport layer segments it into smaller chunks.
    - These chunks are called **datagrams or segments** depending on the protocol used.
- Sometimes some additional information is required to transmit the segment/datagram reliably. The transport layer adds this information to the segment/datagram.
    - Ex. checksum, header, trailer.

### Network Layer
- Network layer messages are termed as **packets**.
- Facilitate the transportation of packets from one end system to another and help to determine the best routes that messages should take from one end system to another.
- Routing protocols are applications that run on the network layer and exchange messages with each other to develop information that helps them route transport layer messages.

### Data Link Layer
- Allows directly connected hosts to communicate. Sometimes these hosts are the only two things on a physical medium.
- The challenges that this layer addresses include **flow control** and **error detection/correction**.
- Encapsulates packets for transmission across a single link.
- Resolves transmission conflicts i.e., when two end systems send a message at the same time across one singular link.
- Handles addressing If the data link is a broadcast medium, addressing is another data link layer problem.
- Multiplexing & Demultiplexing

### Physical Layer
- Consists largely of hardware.
- Provides a solid electrical and mechanical medium to transmit the data.
- Transmits bits. Not logical packets, datagrams, or segments.

