1) All aspects of the assignment have been correctly implemented and function as expected.

2) I collaborated with Sibonay Koo regarding my JSON.parse function. I wasn't understanding its pupose at first, but we worked it out.

3) I spent approximately 2 hours on this assignment, an hour and a half of which was spent debugging the error "request.onreadystatechange = parseData();". I now fully understand the principal of first class functions and why the assignment should be "parseData". 

4) It is NOT possible to request data from a different origin or from the local machine using the XMLHttpRequest API. This is because that functionality would violate the Same-origin policy. Same-origin policy is necessary for web security and enforced by the browser. It's essentially the idea that you can't request data from a different server (as in, a server of a different origin/domain as you). However,  Cross-site HTTP requests (CORS) can be enabled on a server to allow outside scripts to bypass the Same-origin policy. The same principle and reasoning of Same-origin policy applies to local files as well.